#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define debug(x) cout<<#x<<": "<<x<<endl

#define ld double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000000000000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll a,b;
    cin >> a >> b;

    cout << "100 100" << endl;

    char ans[101][101];

    rep(i,101)
    {
        rep(j,101)
        {
            ans[i][j] = 'g';
        }
    }

    b--;
    a--;

    ll x = 1;
    ll y = 1;

    while(a!=0)
    {
        ans[x][y] = '.';
        y+=2;
        if(y>100)
        {
            y = 1;
            x+=2;
        }
        a--;
    }

    fr(i,1,x)
    {
        fr(j,1,100)
        {
            if(ans[i][j]=='g')
                ans[i][j] = '#';
        }
    }

    x++;
    
    fr(i,1,100)
    {
        ans[x][i] = '#';
    }

    x++;
    fr(i,1,100)
    {
        ans[x][i] = '.'; 
    }

    x++;

    ll x2 = x;
    y = 1;

    while(b!=0)
    {
        ans[x][y] = '#';
        y+=2;
        if(y>100)
        {
            y = 1;
            x+=2;
        }
        b--;
    }    

    fr(i,x2,100)
    {
        fr(j,1,100)
        {
            if(ans[i][j]=='g')
                ans[i][j] = '.';
        }
    }

    fr(i,1,100)
    {
        fr(j,1,100)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}