#include<bits/stdc++.h>
using namespace std;
int main(){
  long long k;
  char s[200000];
  cin >> s >> k;
  long long n=strlen(s);
  for(long long i=0;i<min(n,k);i++){
    if(s[i]!='1'){
      cout << s[i];
      return 0;
    }
  }
  cout << 1;
}
