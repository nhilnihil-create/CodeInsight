#include<bits/stdc++.h>
using namespace std;
using lli = long long;
string s;

int main(void){
  cin >> s;
  lli a=0, b=0;
  lli n = s.size();
  for(lli i = 0; i < n; i++){
    if(s[i] == 'B'){
      a+=n-1-i;
      b++;
    }
  }
  cout << a-b*(b-1)/2 << endl;
  return 0;
}
