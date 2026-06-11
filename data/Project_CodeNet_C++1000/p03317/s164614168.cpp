#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

ll N;

ll func ( ll K, ll pos )
{
  if ( K == N ) return 1;
  ll l,r,maxl,minl;
  ll ans = 0;
  l = pos-1; r = N-pos;
  maxl = max(l,r); minl = min(l,r);

  //cout << maxl << " " << minl << "\n";

  if ( minl < K ) {
    ++ans;
    maxl -=(K-minl-1);
    ans += ( maxl/(K-1) );
    if ( maxl%(K-1) > 0 ) ++ans;
  } else {
    ++ans;
    minl -= ( minl%(K-1) );
    ans += ( minl/(K-1) );
    maxl -= ( K-(minl%(K-1))-1 );
    ans += ( maxl/(K-1) );
    if ( maxl%(K-1) > 0 ) ++ans;
  }

  return ans;
}

int main()
{
  ll K;
  cin >> N >> K;
  ll pos;
  for ( int i = 1; i <= N; ++i ) {
    int tmp;
    scanf("%d", &tmp);
    if ( tmp == 1 ) pos = i;
  }

  cout << func ( K,pos) << endl;

}
