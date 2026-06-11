//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define eps 1e-8
#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const ll mod= 1e9+7;
long double PI = acosl(-1);
const ll infl = 1e18+0;
const int inf = 1e9;
const int nmax = 2e5+5;
const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

vector<int>koi[nmax];
ll dp[nmax];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<int>v2(n);
    for(int &x : v2) cin>>x;
    vector<int>v;
    for(int x : v2){
        if(v.empty()) v.push_back(x);
        else {
            if(v.back() != x) v.push_back(x);
        }
    }

    for(int i=0; i<v.size(); i++){
        koi[v[i]].push_back(i);
    }
    int sz = v.size();

    for(int i=0; i<sz; i++){
        if(i==0) dp[i] = 1;
        else dp[i] = dp[i-1];
        int x = v[i];
        int sodo = lower_bound(koi[x].begin(), koi[x].end(), i) - koi[x].begin();
        if(sodo)
            dp[i] = (dp[i] + dp[koi[x][sodo-1]] )%mod;
    }

    cout<<dp[sz-1];
}
/*
*/
