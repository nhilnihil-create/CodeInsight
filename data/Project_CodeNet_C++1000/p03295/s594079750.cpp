#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

bool hikaku(P a, P b)
{
    return a.second < b.second;
}
int main()
{
    int n,m;cin >> n >> m;
    vector<P> vc(m);
    rep(i,m)
    {
        int a,b;cin >> a >> b;
        vc[i] = P(a,b);
    }

    sort(vc.begin(),vc.end(), hikaku);
    int counter = 0;
    int temp = 0;
    rep(i,m)
    {
        if (i==0)
        {
            counter++;
            temp = vc[i].second;
        }

        if(vc[i].first < temp) continue;
        counter++;
        temp = vc[i].second;
        
    }
    cout << counter << endl;
}