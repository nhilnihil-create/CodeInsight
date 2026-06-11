#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define dump(x) cout << (x) << endl
#define LMAX 9223372036854775807LL
#define LMIN -9223372036854775807LL
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e18;
const ll mod = 1e9 + 7;

int main(){
    int q;
    cin >> q;
    REP(i,q){
        ll a ,b;
        cin >> a >> b;
        if(b < a)swap(a,b);
        if(a == b)dump(2 * a - 2);
        else if(a + 1 == b)dump(2 * a - 2);
        else {
            ll c = ceil(sqrt(a * b)) - 1;
            if(c * (c + 1) >= a * b)dump(2 * c - 2);
            else dump(2 * c - 1);
        }
    }
}
