#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,k;
  cin >> n >> k;

  string s;
  cin >> s;

  if(s[k-1]=='A')s[k-1]='a';
  else if(s[k-1]=='B')s[k-1]='b';
  else s[k-1]='c';

  for(int i=0;i<n;i++)cout << s[i];
  cout << endl;

}