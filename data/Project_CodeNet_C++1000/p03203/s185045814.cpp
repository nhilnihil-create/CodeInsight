#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> P;
#define REP(i, x, n) for(int i = x ; i < n ; ++i)
#define rep(i, n) for(int i = 0 ; i < n ; ++i)
#define repr(i, n) for(int i = n - 1 ; i >= 0 ; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort((x).begin(), (x).end())

const int IINF = 1e9 + 10;
const long long LLINF = (long long)1e18 + 10;
const long long MOD = (long long)1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> v(h, IINF);
    rep(i, n){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        v[x] = min(v[x], y);
    }
    int right = 0, ans = h;
    rep(i, h - 1){
        if(v[i + 1] <= right){
            ans = i + 1;
            break;
        }else if(right + 1 < v[i + 1]){
            ++right;
        }
    }
    cout << ans << endl;
    return 0;
}