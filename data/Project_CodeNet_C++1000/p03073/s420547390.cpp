#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    int N;
    string S, S1, S2;
    cin >> S;

    N = S.length();
    S1 = S; S2 = S;
    if (S2[0] == '0') S2[0] = '1';
    else S2[0] = '0';

    int res = 0, pos = 1, ans;
    REP(i, N-1){
        if (S1[i] == S1[i+1]){
            res++;
            if (S1[i+1] == '0') S1[i+1] = '1';
            else S1[i+1] = '0';
        }
    }

    REP(i, N-1){
        if (S2[i] == S2[i+1]){
            pos++;
            if (S2[i+1] == '0') S2[i+1] = '1';
            else S2[i+1] = '0';
        }
    }

    ans = min(res, pos);
    cout << ans << endl;
}