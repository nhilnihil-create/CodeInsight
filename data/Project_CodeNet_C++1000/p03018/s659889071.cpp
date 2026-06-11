// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll n,ans=0,a_idx=-1;
  string s="",t;
  cin >> t;
  n = t.size();
  for(int i=0;i<n;i++){
    if(t[i]=='A') s+='A';
    else if(i!=n-1&&t[i]=='B'&&t[i+1]=='C') s+='D',i++;
    else s+=t[i];
  }
  n = s.size();
  for(int i=0;i<n-1;i++){
    if(s[i]=='A'){
      if(a_idx == -1){
        a_idx = i;
      }
      if(s[i+1]=='D'){
        ans += i-a_idx+1;
        s[a_idx]='D';
        s[i+1]='A';
        a_idx++;
      }
    }else{
      a_idx = -1;
    }
  }
  cout << ans << endl;
}
