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

int n, l, ans, N;
int dp[10][10];
string s;

int stt(int id, int mask)
{
    if(id == n)
        return mask == 7;

    if(dp[id][mask] != -1)
        return dp[id][mask];

    int ans = 0;
    ans += stt(id + 1, _set(mask, 0)) + stt(id + 1, _set(mask, 1)) + stt(id + 1, _set(mask, 2));

    return dp[id][mask] = ans;
}

void con(int id)
{
    if(id == l){
        int nn = n;
        int a = 0, b = 0, c = 0;
        while(nn){
            if(nn % 10 == 3)
                a++;
            if(nn % 10 == 5)
                b++;
            if(nn % 10 == 7)
                c++;
            nn /= 10;
        }
        if(!a || !b || !c)
            return;

        ans += (n <= N);
        return;
    }

    int x[] = {3, 5, 7};
    for(int i = 0; i < 3; i++){
        n *= 10, n += x[i];
        con(id + 1);
        n /= 10;
    }
}

int main()
{
    string s;
    cin >> s;

    l = s.size();
    for(int i = 0; i < l; i++)
        N *= 10, N += s[i] - '0';

    for(int i = 3; i < l; i++){
        mem(dp, -1);
        n = i, ans += stt(0, 0);
    }

    n = 0;
    con(0);

    cout << ans << '\n';
    return 0;
}
