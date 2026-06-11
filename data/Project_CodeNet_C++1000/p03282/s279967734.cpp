#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1061109567;
const double EPS = 1e-10;

int main(){
  string s;
  ll k,cnt;
  cin>>s>>k;
  for(int i=0;i<100000;i++){
    if(s[i]!='1'){
      break;
    }else{
      cnt++;
    }
  }
  if(k-1<=cnt){
    cout<<s[k-1]<<endl;
  }else{
    cout<<s[cnt]<<endl;
  }
}