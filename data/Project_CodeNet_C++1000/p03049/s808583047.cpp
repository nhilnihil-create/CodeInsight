#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int ans=0;
  int ca=0;
  int cb=0;
  int cba=0;
  for(int i=0;i<N;i++){
    string s;
    cin >> s;
    for(int j=0;j<s.size()-1;j++){
      if(s.substr(j,2)=="AB"){
        ans++;
      }
    }
    if((s.front()=='B')&&(s.back()=='A')){
      cba++;
    }else if(s.front()=='B'){
      cb++;
    }else if(s.back()=='A'){
      ca++;
    }
  }
  ans+=min(ca,cb);
  if(max(ca,cb)>0){
    ans+=cba;
  }else{
    ans+=max(0,(cba-1));
  }
  cout << ans << endl;
  return 0;
}
