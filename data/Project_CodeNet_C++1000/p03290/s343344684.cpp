#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, j, n) for (int i = j; i < (int)(n); i++)
#define brep(i, n) for (int i = n; i > 0; i--)
#define BREP(i, j, n) for(int i = n; i > j; i--)
#define TEST cout << "PASS" << endl
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 1e6 + 1e3 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
    int d, g;
    cin >> d >> g;
    g /= 100;
    int p[10], c[10];
    rep(i, d) cin >> p[i] >> c[i];
    rep(i, d) c[i] /= 100;
    int ans = INF;
    for(int i = 0; i < (1 << d); i++){
        bitset<10> s(i);
        int cnt = 0;
        int point = 0;
        int m0 = 0;
        rep(j, d){
            if(s.test(j)){
                cnt += p[j];
                point += (j+1) * p[j] + c[j];
            }else{
                m0 = j+1;
            }
        }
        if(point < g){
            if(m0 == 0 || (g - point + m0 - 1)/m0 > p[m0-1]) continue;
            cnt += (g - point + m0 - 1)/m0;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}