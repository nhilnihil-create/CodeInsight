#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int num_b,num_w,w_all;
  num_b=0;
  num_w=0;
  w_all=0;
  for(int i=0;i<n;++i){
    if(s[i]=='.'){
      w_all++;
    }
  }
  int ans=w_all;
  for(int i=0;i<n;++i){
    int cal=0;
    if(s[i]=='.'){
      num_w++;
    }else{
      num_b++;
    }
    cal=num_b+w_all-num_w;
    ans=min(ans,cal);
  }

  cout << ans << endl;
  return 0;
}
