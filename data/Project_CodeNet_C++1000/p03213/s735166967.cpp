#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

vector<int> e;

void prime_factor(int num)
{
    for (int i = 2; i*i <= num; i++)
    {
        while(num%i==0)
        {
            e[i]++;
            num/=i;
        }
    }
    if(num!=1)e[num]++;
}

int kosu(int num)
{
    int ret=0;
    num--;
    for(auto& u: e)
    {
        if(u>=num) ret++;
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    e.resize(n+1,0);
    for (int i = 2; i < n+1; i++)
    {
        prime_factor(i);
    }
    //for(auto u: e) cout << u << " ";
    //cout << endl;
    int ans = 0;
    ans += kosu(75) + (kosu(15)*(kosu(5)-1)) + (kosu(25)*(kosu(3)-1)) + (kosu(5)*(kosu(5)-1)*(kosu(3)-2)/2);
    cout << ans << endl;
}