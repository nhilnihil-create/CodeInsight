#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  string s;
  string  t;
  cin >> s >>t;

  if(t.size()>=4){
    for(ll i=0;i<s.size();i++){
      if(s[i]!='1'){
        cout << s[i] << endl;
        return 0;
      }
    }
  }
  ll k=stoi(t);
  if(k<=s.size()){
    for(ll i=0;i<k;i++){
      if(s[i]!='1'){
        cout << s[i] << endl;
        return 0;
      }
    }
    cout << 1 << endl;;
  }
  else{
    for(ll i=0;i<s.size();i++){
      if(s[i]!='1'){
        cout << s[i] << endl;
        return 0;
      }
    }
  }


}