#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    ll N;
    cin >> N;
    ll M=0, A=0, R=0, C=0, H=0;
    REP(i,0,N) {
        string s;
        cin >> s;
        if(s[0] == 'M') ++M;
        if(s[0] == 'A') ++A;
        if(s[0] == 'R') ++R;
        if(s[0] == 'C') ++C;
        if(s[0] == 'H') ++H;
    }
    PR(M*(A*R+A*C+A*H+R*C+R*H+C*H)+A*(R*C+R*H+C*H)+R*C*H);



    return 0;
}

/*



*/