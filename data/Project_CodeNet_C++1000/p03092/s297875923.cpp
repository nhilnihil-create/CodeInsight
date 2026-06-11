#include<bits/stdc++.h>
#define mino "test"
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define matrix vector<vector<ll>>
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define Down(i,a,b) for(int i=a; i>=b; i--)
#define FOR_(i,a,b) for(int i=a; i<b; i++)
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e18

const int N = 5e3 + 5;

using namespace std;

typedef pair<int,int> pii;


int n;
int a[N];
ll F[N][N];
ll A, B;

void nhap()
{
    cin >> n >> A >> B;
    FOR(i,1,n) cin >> a[i];

    FOR(i,1,n) F[1][i] = oo;
    F[1][a[1]] = 0;
    F[1][0] = A;
}

void xuli()
{
    ll res = oo;
    if(n == 1) res = 0;
    FOR(i,2,n)
    {
        FOR(j,0,n) F[i][j] = oo;
        FOR(j,0,n)
        {
            if(j > a[i]) F[i][j] = min(F[i][j], F[i-1][j] + B);
            else if(j < a[i])
            {
                F[i][a[i]] = min(F[i][a[i]], F[i-1][j]);
                F[i][j] = min(F[i][j], F[i-1][j] + A);
            }
            if(i == n) res = min(res, F[i][j]);
        }
    }
    cout << res;
}

int main()
{
    //freopen(mino".inp","r",stdin);
    //freopen(mino".out","w",stdout);
    nhap();
    xuli();
}
