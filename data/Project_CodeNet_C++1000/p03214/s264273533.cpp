#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    ll n;
    cin >> n;
    vector<double> a(n);
    double sum = 0;
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }
    double mean = sum/double(n);
    ll ans  = 0;
    rep(i, n)if(abs(a[ans]-mean) > abs(a[i]-mean))ans = i;
    cout << ans << endl;
}