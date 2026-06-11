//Reminder Reminder
#include <iostream>
using namespace std;
int main(){
  long long N,K;cin>>N>>K;
  long long ans = 0;
  if(K==0){
    cout << N*N << endl;
    return 0;
  }
  for(long long i = K+1; N >= i; i++){
    //?%i >= K
    ans += (N/i)*(i-1-(K-1));
    ans += max(0LL,(N%i)-K+1);
  }
  cout << ans << endl;
}