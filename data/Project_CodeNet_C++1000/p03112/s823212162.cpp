#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 1LL<<60;
/* -- template -- */

void nearestNtoM(const int N, const int M, ll arrayN[], ll arrayM[], ll array[]){
    rep(i, N){
        int l = 0, r = M;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(arrayM[mid] < arrayN[i]){
                l = mid;
            }else{
                r = mid;
            }
        }
        array[i] = min(abs(arrayN[i] - arrayM[l]), abs(arrayN[i] - arrayM[r]));
    }
}

int main(){
    int shrineCount, templeCount, Q;cin >> shrineCount >> templeCount >> Q;
    ll temple[templeCount + 1], shrine[shrineCount + 1];
    temple[templeCount] = LLINF, shrine[shrineCount] = LLINF;
    rep(i, shrineCount){
        cin >> shrine[i];
    }
    rep(i, templeCount){
        cin >> temple[i];
    }
    ll nearestStoT[shrineCount];
    nearestNtoM(shrineCount, templeCount, shrine, temple, nearestStoT);
    ll nearestTtoS[templeCount];
    nearestNtoM(templeCount, shrineCount, temple, shrine, nearestTtoS);
    ll q[Q];
    rep(i, Q){
        cin >> q[i];
    }
    rep(i, Q){
        int l = 0, r = templeCount;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(temple[mid] < q[i]){
                l = mid;
            }else{
                r = mid;
            }
        }
        int tl = l, tr = r;
        l = 0, r = shrineCount;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(shrine[mid] < q[i]){
                l = mid;
            }else{
                r = mid;
            }
        }
        int sl = l, sr = r;
        cout << min<ll>(min<ll>(nearestStoT[sl] + abs(shrine[sl] - q[i]), nearestStoT[sr] + abs(shrine[sr] - q[i])), min<ll>(nearestTtoS[tl] + abs(temple[tl] - q[i]), nearestTtoS[tr] + abs(temple[tr] - q[i]))) << endl;
    }
}
