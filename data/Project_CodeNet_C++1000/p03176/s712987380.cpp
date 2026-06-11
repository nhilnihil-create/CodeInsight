#include "bits/stdc++.h"
using namespace std;
#define F first
#define S second
#define show(x) cout<<#x<<" "<<x<<" ";
#define f(i,j,k) for(int i = j;i<=k;i++)
#define fr(i,j,k) for(int i = j;i>=k;i--)
#define ll long long
#define all(A)  A.begin(),A.end()  
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);  
const int MSIZE = 2e5+5;
const int MOD = 1e9+7;


int arr[MSIZE], ht[MSIZE];
map<int,ll> m; 
ll dp[MSIZE];

ll solve(int& n) {
    dp[0] = arr[0];
    m[ht[0]] = dp[0];
    f(i,1,n-1) {
        dp[i] = arr[i];
        auto it = m.lower_bound(ht[i]);
        if(it!=m.begin())   dp[i]+= (--it)->second;
        m[ht[i]] = dp[i];
        it = m.upper_bound(ht[i]);
        while(it!=m.end() && (it->second)<=dp[i]) {
            auto t = it; it++;
            m.erase(t);
        }
    }
    return *max_element(dp,dp+n);
}

int main(){

    FIO
    int n; cin>>n;
    f(i,0,n-1)  cin>>ht[i];
    f(i,0,n-1)  cin>>arr[i];
    cout<<solve(n)<<endl;
    return 0;

}
    
