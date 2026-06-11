#include <iostream>
using namespace std;
int main(){
  long n,k;
  cin >> n >> k;
  long ans = 0;
  if(k==0){
    cout << n*n << endl;
    return 0;
  }
  for(int i = k+1;i<=n;i++){
    ans+=((n/i)*(i-k));
    ans+=max(0L,n%i-k+1);
  }
  cout << ans << endl;
}
