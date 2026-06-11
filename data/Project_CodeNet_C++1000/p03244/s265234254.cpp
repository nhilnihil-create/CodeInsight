#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
 
int main() {
    int n;
    cin >> n;
    vector<int>v(n);
    vector<pair<int,int>>cnt1(100001);
    vector<pair<int, int>>cnt2(100001);
    rep(i, 0, n){
        cin >> v[i];
        if(i%2==0)cnt1[v[i]].second=v[i];
        else cnt2[v[i]].second=v[i];
    }
    rep(i, 0, n){
        if(i%2==0)cnt1[v[i]].first++;
        else cnt2[v[i]].first++;
    }
    sort(cnt1.begin(),cnt1.end(), greater<pair<int, int>>());
    sort(cnt2.begin(),cnt2.end(), greater<pair<int, int>>());
    if(cnt1[0].second!=cnt2[0].second)cout << n-cnt1[0].first-cnt2[0].first << endl;
    else{
        if((cnt1[0].first - cnt1[1].first)-(cnt2[0].first - cnt2[1].first)>=0){
            cout << n - cnt1[0].first-cnt2[1].first << endl;
        }else{
            cout << n - cnt1[1].first-cnt2[0].first << endl;
        }
    }
}