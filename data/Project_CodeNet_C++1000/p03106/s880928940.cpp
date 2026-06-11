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
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int a,b ,k; cin >> a >> b >> k;
    k--;
    int div = 1;
    int counter = 0;
    vector<int> ans;
    while(div<=max(a,b))
    {
        if(a%div==0 && b%div==0)
        {
            ans.push_back(div);
        }
        div++;
    }
    sort(ans.begin(),ans.end(), greater<int>());    

    cout << ans[k] << endl;
}