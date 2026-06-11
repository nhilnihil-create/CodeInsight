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

int keta_sum(int num)
{
    int ret = 0;
    while(num>0)
    {
        ret += num%10;
        num /=10;
    }
    return ret;
}
int main()
{
    int n;cin >> n;
    int mn = INF;
    for (int i = 1; i <=n-1; i++)
    {
        int temp = 0;
        temp += keta_sum(i);
        temp += keta_sum(n-i);
        mn = min(mn, temp);
    }
    cout << mn << endl;
}