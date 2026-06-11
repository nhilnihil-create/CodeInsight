#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define DD double
#define Pb push_back
#define Bp pop_back
#define Pf push_front
#define Fp pop_front
#define Ub upper_bound
#define Lb lower_bound
#define In insert
#define All(x) x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define X first
#define Y second
#define mx1 10
#define mx2 110
#define mx3 1010
#define mx4 10010
#define mx5 100010
#define mx6 1000010

typedef vector<LL> Vl;
typedef vector<DD> Vd;
typedef vector<bool> Vb;
typedef vector<Vl> VVl;
typedef pair<LL, LL> Pll;
typedef pair<DD, DD> Pdd;
typedef vector<Pll> Vpl;
typedef vector<Pdd> Vpd;
typedef queue<LL> Ql;
typedef stack<LL> Sl;
typedef deque<LL> Dl;

LL _set(LL N, LL pos) {return N = N | (1 << pos);}
LL _reset(LL N, LL pos) {return N = N & ~(1 << pos);}
bool _check(LL N, LL pos) {return (bool)(N & (1 << pos));}
bool _upper(char a) {return a >= 'A' && a <= 'Z';}
bool _lower(char a) {return a >= 'a' && a <= 'z';}
bool _digit(char a) {return a >= '0' && a <= '9';}

LL dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
LL dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

///**************************DONE****************************///

int dp[70][70][70];

int stt(int a, int b, int c)
{
    if(a == b && b == c)
        return 0;

    if(a > 60 || b > 60 || c > 60)
        return 1e5;

    if(dp[a][b][c] != -1)
        return dp[a][b][c];

    int ans = 1 + stt(a + 1, b + 1, c);
    ans = min(ans, 1 + stt(a, b + 1, c + 1));
    ans = min(ans, 1 + stt(a + 1, b, c + 1));
    ans = min(ans, 1 + stt(a + 2, b, c));
    ans = min(ans, 1 + stt(a, b + 2, c));
    ans = min(ans, 1 + stt(a, b, c + 2));

    return dp[a][b][c] = ans;
}

int main()
{
    mem(dp, -1);
    int a, b, c;
    cin >> a >> b >> c;

    cout << stt(a, b, c) << '\n';
    return 0;
}
