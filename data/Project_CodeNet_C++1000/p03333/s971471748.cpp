#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF ((int)1e9)
#define INFLL ((ll)1e18)
#define MOD (1000000007LL)

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    vector<ll> VL(N), VR(N);
    for (int n=0; n<N; ++n) {
        cin >> VL[n] >> VR[n];
    }
    
    sort(VL.begin(), VL.end(), greater<ll>());
    sort(VR.begin(), VR.end());
    
    for (int n=1; n<N; ++n) {
        VL[n] += VL[n-1];
        VR[n] += VR[n-1];
    }
    
    ll Res = VL[0] - VR[0];
    Res = max(Res, VL[0] -VR[1]);
    for (int n=0; n<N-1; ++n) {
        for (int dif=-1; dif<=1; ++dif) {
            Res = max(Res, VL[n]-VR[n+dif]);
        }
    }
    Res *= 2;
    cout << Res << endl;

    return 0;
}
