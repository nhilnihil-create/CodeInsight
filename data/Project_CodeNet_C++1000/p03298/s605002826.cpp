#include<bits/stdc++.h>

#define mx 100005
#define md 1000000007

using namespace std;

map<string, int> mp;
string s;
long long n, ans;

int main(){
  cin >> n >> s;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < (1<<n); j++){
      int l = 0, r = n;
      char t[20]; t[n+1] = '\0';
      for(int k = 0; k < n; k++){
        if((j>>k)&1) t[l++] = s[i ? 2*n-1-k : k];
        else t[r--] = s[i ? 2*n-1-k : k];
      }
      t[l] = 'A';
      if(i) ans += mp[(string)t];
      else mp[(string)t]++;
    }
  }
  printf("%lld\n", ans);
}