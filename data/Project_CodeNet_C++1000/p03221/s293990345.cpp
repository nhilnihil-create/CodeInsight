#include<bits/stdc++.h>
using namespace std;


int main(){
  int n,m;
  cin >> n >> m;
  vector<tuple<int,int,int>> cal(m);
  for(int i=0;i<m;++i){
    int p,y;
    cin >> p >> y;
    cal.emplace_back(p,y,i);
  }
  sort(cal.begin(),cal.end());
  vector<string> ans(m);
  int pre=-1;
  int num=0;
  for(auto v : cal){
    if(pre==-1){
      pre=get<0>(v);
    }
    if(pre==get<0>(v)){
      num++;
    }else{
      num=1;
      pre=get<0>(v);
    }
    string tmp1,tmp2,tmp;
    tmp1=to_string(get<0>(v));
    while(tmp1.size()<6){
      tmp1="0"+tmp1;
    }
    tmp2=to_string(num);
    while(tmp2.size()<6){
      tmp2="0"+tmp2;
    }
    tmp=tmp1+tmp2;
    ans[get<2>(v)]=tmp;
  }
  for(int i=0;i<m;++i) cout << ans[i] << endl;

  return 0;
}
