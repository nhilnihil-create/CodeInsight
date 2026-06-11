#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<char> vi;
int main()
{
    // freopen("B.04.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q=0;
    cin >> n;
    vi a(n);
    vi colors(4, 0);
    trav(it, a)
    {
        cin >> it;
    }
    rep(i, 0, n)
    {
        if (a[i] == 'P')
        {
            colors[0]++;
        }
        if (a[i] == 'W')
        {
            colors[1]++;
        }
        if (a[i] == 'G')
        {
            colors[2]++;
        }
        if (a[i] == 'Y')
        {
            colors[3]++;
        }
    }
    rep(i, 0, 4){
        if(colors[i]!=0){
            q++;
        }
    }
    if(q==3){
        cout << "Three" << endl;
    }
    else{
        cout << "Four" << endl;
    }
    return 0;
}