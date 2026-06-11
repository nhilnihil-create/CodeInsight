#include <bits/stdc++.h>
using namespace std;
int vsum(vector<int> v){
  int a=0;
  for(int i=0;i<v.size();i++)a+=v[i];
  return a;
}
int main(){
  int i,j,tmp,D,G,ans=1000;
  cin>>D>>G;
  vector<int> p(D),c(D);
  for(i=0;i<D;i++)cin>>p[i]>>c[i];
  for(tmp=0;tmp<(1<<D);tmp++){
    bitset<10> s(tmp);
    int cnt=0,point=0;
    for(i=0;i<D;i++){
      if(s[i]){
        cnt+=p[i];
        point+=p[i]*(i+1)*100+c[i];
      }
    }
    if(point>=G)ans=min(ans,cnt);
    else {
      for(i=0;i<D;i++){
        if(!s[D-1-i]){
          for(j=0;j<p[D-1-i];j++){
            point+=(D-i)*100;
            cnt++;
            if(point>=G){ans=min(ans,cnt);break;}
          }
          break;
        }
      }
    }
  }
  cout<<ans<<endl;
}