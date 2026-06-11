#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  string s;
  cin >> s;
  ll n,i,b,r;
  n=s.size();
  r=0;
  b=0;
  for(i=0;i<n;i++){
    if(s.at(i)=='B'){
      r += i;
      b++;
    }
  }
  cout << (n*2-b-1)*b/2-r << endl;
}