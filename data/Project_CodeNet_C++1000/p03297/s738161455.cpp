#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define scontains(c, x) ((c).find(x) != (c).end())   //O(log n)
#define contains(c, x) (find((c).begin(),(c).end(),x) != (c).end()) //O(n)
#define ill(_x)  ll _x;scanf("%lld",&_x);
#define idb(_x)  double _x;scanf("%lf",&_x);
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vs vector<string>
#define in0(x, a, b)((x)>=a && (x)<=b    )
#define in1(x, a, b)((x)>a && (x)<b)
#define  rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const double pi = 3.14159265358979323846;
const int INF = 0x3f3f3f3f;
const int MOD = (int) (1e9) + 7;

int tc, q;
map<int, int> factorize(long long n)
{
    map<int, int> factors;
    int count = 0;

    while (!(n % 2)) {
        n >>= 1;
        count++;
    }

    if(count)factors[2] = count;

    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count)
            factors[i] = count;
    }

    if (n > 2)
        factors[n] = 1;
    return factors;
}



void _() {
    ll tc, a, b, c, d;
    cin >> tc;
    while(tc --){
        cin >> a >> b >> c >>d;
        if(b>d || a<b){
            cout << "No\n";
            continue;
        }
        else{
            ll g = __gcd(b,d);
            ll s = a - (a-c-1)/g*g;
            if(s < b){
                cout << "No\n";
                continue;
            }
            cout << "Yes\n";
        }
    }

};


int main() {
#if __MINGW32__
    freopen("C:\\Users\\hiroo\\CLionProjects\\competitive\\Input.txt", "r", stdin);
    freopen("C:\\Users\\hiroo\\CLionProjects\\competitive\\Output.txt", "w", stdout);

#endif

    _();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;

}