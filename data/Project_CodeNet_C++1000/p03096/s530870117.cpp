#include<bits/stdc++.h>
using namespace std;

#define int long long

#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 2e5 + 5;

int M[N];

signed main(){
    int n;
	cin >> n;    
    int pre = 1;
    int prex = 0;
    int dp;
    for(int i=1; i<=n; i++){
        int x;
        scanf("%lld", &x);
        if(x == prex) continue;
    	dp = (M[x] + pre) % mod;
//        cout << i << " " << dp << " ss\n";
        M[x] = (M[x] + pre) % mod;
        pre = dp;
        prex = x;
    }
    
    cout << dp;
    return 0;
}