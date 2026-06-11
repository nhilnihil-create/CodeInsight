#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;

/* --------------------------------------------------- */

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    int cnt = 0;
    for(int i = max(a, b); i > 0; i--) {
        if(a % i == 0 && b % i == 0) cnt++;
        if(cnt == k) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}