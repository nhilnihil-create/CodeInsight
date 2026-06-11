#include <iostream>
#include <vector>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, Z, W;
    cin >> N >> Z >> W;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
  
  	if(N == 1) cout << abs(W-a[0]) << endl;
  	else cout << max(abs(W-a[N-1]), abs(a[N-1]-a[N-2])) << endl;
  
  	return 0;
}
