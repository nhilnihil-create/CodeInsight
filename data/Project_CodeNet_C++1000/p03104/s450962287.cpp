#include <iostream>
using namespace std;

int main(){
  long long int a,b;
  cin >> a >> b;
  long long int ans = 0;
  for(int i = 0; 62 > i; i++){
    long long int mod = 1LL << (1 + i);
    ans += mod/2*(((b/mod - a/mod) * (mod/2) - max(0LL, a%mod - mod/2) + max(0LL,b%mod - mod/2 + 1))%2);
  }
  cout <<ans<<endl;
 return 0; 
}