#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
#define mk make_pair
#define pb push_back
#define pf push_front
typedef pair<int, int> pii;
const int mod = 1000000007;
const int INF = 1000000009;
const long long INFL = 1000000000000000018ll;

int N, t[110];
int vl[40040], vr[40040], v[110];
int L;
int vmax[40040];
double suzuki = 0.5 * 0.5 * 0.5;

signed main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> t[i];
        L += t[i];
    }
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    int cur = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < t[i] * 2; j++){
            vl[cur] = v[i] * 10;
            if(cur > 0)vr[cur - 1] = v[i] * 10;
            //printf("init %2d %2d\n", cur / 2, v[i]);
            cur++;
        }
    }
    vl[0] = 5;
    vr[cur - 1] = 0;
    for(int i = 1; i < cur; i++){
        vl[i] = min(vl[i], vl[i - 1] + 5);
    }
    for(int i = cur - 2; i >= 0; i--){
        vr[i] = min(vr[i], vr[i + 1] + 5);
    }
    for(int i = 0; i < cur - 1; i++){
        vmax[i] = min(vl[i], vr[i]);
        //printf("%3d: %3d\n", i / 2, vmax[i]);
    }
    double ans = 0.0;
    for(int i = 0; i < cur; i++){
        if(vmax[i - 1] == vmax[i]){
            ans += (double)vmax[i] * 0.05;
        }
        else if(vmax[i - 1] < vmax[i]){
            ans += (double)vmax[i - 1] * 0.05 + suzuki;
        }
        else {
            ans += (double)vmax[i] * 0.05 + suzuki;
        }
        //printf("%2d: %.2f: %.2f\n", i / 2, (double)vmax[i] / 10.0, ans);
    }
    printf("%.10f\n", ans);

}
/*

*/


