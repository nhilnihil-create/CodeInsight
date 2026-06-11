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
    vector<int> a(n);
    rep(i,n)
    {
        cin >> a[i];
        a[i] -= (i+1);
    }
    

    sort(a.begin(),a.end());
    
    int med;
    ll sum_1 = 0;
    ll sum_2 = 0;
    ll sum = 0;
    if (n%2==0)
    {
        med =  (a[n/2]+a[n/2-1])/2;
        rep(i,n)
        {
            sum_1 += abs(a[i] - med);
            sum_2 += abs(a[i] - med-1);
        }
        cout << min(sum_1,sum_2) << endl;
    }else
    {
        med = a[n/2];
        //cout << med << endl;
        rep(i,n)
        {
            sum += abs(a[i]-med);
        }
        cout << sum << endl;
    }
    
    
}