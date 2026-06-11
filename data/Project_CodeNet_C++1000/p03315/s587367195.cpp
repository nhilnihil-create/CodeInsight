#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  
  int cnt=0;
  rep(i,4){
    if(s[i]=='+') cnt++;
  }
  cout<<2*cnt-4<<endl;

  return 0;
}