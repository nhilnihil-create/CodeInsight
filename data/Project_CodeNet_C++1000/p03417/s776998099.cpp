#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    int N,M;
    cin >> N >> M;
    
    if(M==1 && 1==N){
        cout << 1 << endl;
        return 0;
    }
    if (N == 1 && 1 < M){
        cout << M-2 << endl;
        return 0;
    }
    if (M == 1 && 1 < N){
        cout << N-2 << endl;
        return 0;
    }
    ll ans = (ll)(N-2)*(M-2);
    cout << ans << endl;
    
    return 0;
}