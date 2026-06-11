#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 2e5 + 5;

typedef pair<ll,int>    ii;

ii  a[N];
int s[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;

    for(int i = 1 ; i <= n ; ++i)   {
        ll  x;  cin >> x;
        a[i].X = x;
        a[i].Y = i;
    }
    sort(a + 1,a + 1 + n);
    fill(s + 1,s + 1 + n,1);

    vector<ii>  res;

    ll  Sum = 0;

    for(int i = n ; i >= 2 ; --i)   {
        ll  val = a[i].X + s[i] + s[i] - n;
        int pos = lower_bound(a + 1,a + 1 + n,ii(val,0)) - a;

        if (a[pos].X != val)    {
            cout << "-1";
            return  0;
        }
        s[pos] += s[i]; res.pb(a[pos].Y,a[i].Y);
        Sum += s[i];
    }
    if (Sum != a[1].X)  {
        cout << "-1";
        return  0;
    }
    for(ii  e : res)
        cout << e.X << " ",
        cout << e.Y << "\n";
}
