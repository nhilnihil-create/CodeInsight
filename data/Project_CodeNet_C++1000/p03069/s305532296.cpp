#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;




int dp[maxn][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int n;
    string s;
    cin>>n>>s;
    vector<int> a(n,0);
    for (int i=0; i<n; i++) {
	if (s[i]=='#') a[i]=1;
    }

    dp[0][a[0]^1]++;

    for (int i=1; i<n; i++) {
	dp[i][a[i]^1]++;
	dp[i][1] += min(dp[i-1][0],dp[i-1][1]);
	dp[i][0] += dp[i-1][0];
    }

    cout<<min(dp[n-1][0],dp[n-1][1])<<endl;
    
    
    return 0;
}
