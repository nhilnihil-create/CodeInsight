#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
const int INF=1e5;

int main(){
  string s;
  cin >> s;
  long long n=s.length();
  long long last=n-1;
  while(s[last]=='B')last--;
  long long ans=0;
  for(long long i=last-1;i>=0;i--){
    if(s[i]=='B'){
      ans += last - i;
      last--;
    }
  }
  cout << ans << endl;
}

