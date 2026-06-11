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
    int n;
    cin >> n;
    vector<int> a(n+2);
    a[0] = 0;
    for (int i = 1; i < n+1; i++)
    {
        cin >> a[i];
    }
    a[n+1] = 0;
    int sum = 0;
    for (int i = 1; i < n+1; i++)
    {
        sum += abs(a[i]-a[i-1]);
    }
    sum += abs(a[0]-a[n]);
    //cout << sum << endl;
    for (int i = 1; i < n + 1; i++)
    {
        cout << sum-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i-1]-a[i+1]) << endl;
        
    }
    return 0;
    
}