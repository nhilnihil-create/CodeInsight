#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

vector<P> dp(10020,make_pair(-1000000,0));
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> vec={0,2,5,5,4,5,6,3,7,6};
    vector<int> a(m);
    rp(i,m) cin >> a.at(i);
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    dp[0]=make_pair(0,0);
    for(int i=1; i<=n; i++){
        rp(j,m){
            if(i-vec[a.at(j)]>=0){
                if(dp[i]<make_pair(dp[i-vec[a.at(j)]].first+1,a.at(j))){
                    dp[i]=make_pair(dp[i-vec[a.at(j)]].first+1,a.at(j));
                }
            }
        }
    }
    int digit=dp[n].first;
    rp(i,digit){
        cout << dp[n].second;
        n-=vec[dp[n].second];
    }
    cout << endl;
    return 0;
}