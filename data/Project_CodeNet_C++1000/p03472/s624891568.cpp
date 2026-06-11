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
int main()
{
    int n,h;cin >> n >> h;
    vector<int> a(n);
    vector<int> b(n);
    rep(i,n)
    {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    vector<int> nage;
    for (auto &&i : b)
    {
        if(i >=a[0])
        {
            nage.push_back(i);
        }
    }
    sort(nage.begin(), nage.end(), greater<int>());

    int counter = 0;
    for (auto &&i : nage)
    {
        h -= i;
        // cout << h << endl;
        counter++;
        if(h<=0)
        {
            cout << counter << endl;
            return 0;
        }
    }
    counter += ((h-1)/a[0]+1);
    cout << counter << endl;
}