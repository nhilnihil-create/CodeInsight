#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define ull unsigned long long
#define F first
#define S second
#define nl '\n'
#define pii pair <ll, ll>
#define pb push_back
#define mp make_pair
#define pi 3.14159265358979323846264
#define y1 abacaba
#define fn "abc"
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define pcnt(i) __builtin_popcount(i)
#define lcm(a,b) (a * b) / __gcd(a, b)
#define chill_wave ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pressF freopen("lepus.in", "r", stdin); freopen("lepus.out", "w", stdout);

using namespace std;

const long long MXN = 1e6 + 4;
const long long MAXN = 2e3 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long MAXLOG = 20;

inline void f_math(bool ok = 0) { chill_wave if(ok) { pressF; } }

//int dx[]= {1,0,-1,0}; int dy[]= {0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1}; int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2}; int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0}; int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction


ll a, b, c;

int main() {

    f_math();

    cin >> a >> b >> c;
    if(a + b >= c) {
        cout << b + c;
    } else {
        cout << (a + b + 1) + b;
    }
    return 0;
}
