#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  char s[n+1];
  cin >> s;
  long long p=1,c[26];
  for(char i='a';i<='z';i++){
    c[i-'a']=1;
  }
  for(int i=0;i<n;i++){
    c[s[i]-'a']++;
  }
  for(int i='a';i<='z';i++){
    p*=c[i-'a'];
    p%=1000000007;
  }
  cout << p-1;
}
