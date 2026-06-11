#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define repr(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())

const int IINF = 1e9 + 10;
const long long LLINF = (long long)1e18 + 10;
const long long MOD = (long long)1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int main(){
    int n, h, w;
    cin >> n >> h >> w;
    int ans = (n - h + 1) * (n - w + 1);
    cout << ans << endl;
    return 0;
}