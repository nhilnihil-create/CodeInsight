#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  string s,k="keyence";
  cin >> s;
  int t=s.size();
  int a=0;
  int i=0;
  int j=0;
    while(i<7){
      if(s[i]==k[i]){
        i++;
      }
      else
      break;
    }
    while(j<7){
      if(s[t-1-j]==k[6-j]){
        j++;
      }
      else
      break;
    }
    if(i+j>=7){
      a=1;
    }
    if(a==1){
      cout << "YES" << endl;
    }
    else
      cout << "NO" << endl;
}
