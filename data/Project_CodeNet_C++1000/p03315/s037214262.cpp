#include <iostream>
#include <string>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;

int main(){
  string S;
  cin >> S;
  int ans=0;
  rep(i,4){
    if(S[i]=='+') ans++;
    else ans--;
  }
  cout << ans << endl;

  return 0;
}
