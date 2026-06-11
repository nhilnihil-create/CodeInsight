#include<bits/stdc++.h>
#define mino "A"
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define matrix vector<vector<ll>>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define Down(i,a,b) for(int i = a; i >= b; i--)
#define FOR_(i,a,b) for(int i = a; i < b; i++)
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e9

const int N = 505;

using namespace std;

typedef pair<int,int> pii;


int L;

struct ii
{
    int u, v, w;
};
vector <ii> kq;

void nhap()
{
    cin >> L;
}

void xuli()
{
    int t = 1, n = 1;
    while(t * 2 <= L)
    {
        kq.pb({n,n+1,0});
        kq.pb({n,n+1,t});
        t *= 2;
        n++;
    }

    L -= t;
    Down(i,n-2,0)
    {
        if(L & (1 << i))
        {
            kq.pb({i+1,n,t});
            t += int(1 << i);
        }
    }
    cout << n << ' ' << kq.size() << '\n';
    FOR(i,0,kq.size()-1)
    {
        cout << kq[i].u << ' ' << kq[i].v << ' ' << kq[i].w << endl;
    }
}

int main()
{
    //freopen(mino".inp","r",stdin);
    //freopen(mino".out","w",stdout);
    nhap();
    xuli();
}
