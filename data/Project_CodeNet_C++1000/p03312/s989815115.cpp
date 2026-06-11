#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define repr(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = 1e9 + 10;
const long long LLINF = (long long)1e18 + 10;
const long long MOD = (long long)1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<lint> a(n);
    rep(i, n){
        cin >> a[i];
    }

    REP(i, 1, n){
        a[i] += a[i - 1];
    }

    lint ans = LLINF;

    REP(i, 1, n - 2){
        auto it1 = upper_bound(a.begin() + 1, a.begin() + i, a[i] / 2LL);
        auto it2 = upper_bound(a.begin() + i + 2, a.begin() + (n - 1), a[i] + (a[n - 1] - a[i]) / 2LL);

        vector<lint> p(2), q(2), r(2), s(2);
        p[0] = *(it1 - 1);
        q[0] = a[i] - *(it1 - 1);
        r[0] = *(it2 - 1) - a[i];
        s[0] = a.back() - *(it2 - 1);

        if(it1 == a.begin() + i){
            p[1] = p[0];
            q[1] = q[0];
        }else{
            p[1] = *it1;
            q[1] = a[i] - *it1;
        }

        if(it2 == a.begin() + (n - 1)){
            r[1] = r[0];
            s[1] = s[0];
        }else{
            r[1] = *it2 - a[i];
            s[1] = a.back() - *it2;
        }

        rep(j, 2){
            rep(k, 2){
                ans = min(ans, max({p[j], q[j], r[k], s[k]}) - min({p[j], q[j], r[k], s[k]}));
            }
        }
    }

    cout << ans << endl;

    return 0;

}