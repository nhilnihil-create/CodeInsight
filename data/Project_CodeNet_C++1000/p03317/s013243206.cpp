#include <bits/stdc++.h>
#define MODNum 1000000007
#define REP(type, i, a, b) for( type i = a; i < b; i++ )
typedef long long ll;

using namespace std;

int main (void) {
    int N, K, ans;
    cin >> N >> K;
    vector<int> A(N);
    int Pos;
    REP(int,i,0,N){
        cin >> A.at(i);
    }
    ans = ceil((double)( N - 1 ) / ( K - 1 ));
    cout << ans << endl;
    return 0;
}
