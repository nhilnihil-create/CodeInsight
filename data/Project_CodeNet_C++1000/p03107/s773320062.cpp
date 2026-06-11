#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  string s;
  cin >> s;
  ll a=0,b=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='0')a++;
    else b++;
  }
  cout << 2*min(a,b) << endl;


}