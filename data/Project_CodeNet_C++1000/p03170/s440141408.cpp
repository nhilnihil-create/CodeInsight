#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>
#include <random>

#define ff first
#define ss second

using namespace std;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

pii operator+(pii a, pii b)
{
    return {a.ff+b.ff,a.ss+b.ss};
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<bool> dp(k+1);
    for(int j=0; j<=k; j++){
        for(int i=0; i<n; i++){
            if(j>=a[i]) dp[j]=(dp[j] || !dp[j-a[i]]);
        }
    }
    if(dp[k]) cout<<"First";
    else cout<<"Second";

    return 0;
}
