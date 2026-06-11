#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
  ll sum = 0;
  ll N,K;

  cin >> N >> K;

  if ( K == 0 ) {
    sum = N*N;
  } else {
    for ( int i = K+1; i <= N; ++i ) {
      sum += ( (N/i)*(i-K) );

      if ( (N%i) >= K ) {
        sum += (N%i)-K+1;
      }
    }
  }

  cout << sum << "\n";
}
