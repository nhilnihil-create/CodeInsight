#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int r=0,b=0;
    rep(i,n){
      if(s[i]=='R')r++;
      else b++;
    }
    if(r>b)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}