#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 100005;

int main(){
    int n; cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    vector<int> odd(MAX_N, 0);
    vector<int> even(MAX_N, 0);
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) even[v[i]]++;
        else odd[v[i]]++;
    }
    vector<P> sort_odd, sort_even;
    for(int i = 0; i < MAX_N; ++i){
        sort_odd.push_back(P(odd[i], i));
        sort_even.push_back(P(even[i], i));
    }
    sort(RALL(sort_odd));
    sort(RALL(sort_even));
    int ans = 0;
    if(sort_odd[0].second != sort_even[0].second){//最頻値で考える
        ans =  n - sort_odd[0].first - sort_even[0].first;
    }else{
        ans = min(n - sort_odd[0].first - sort_even[1].first, n - sort_odd[1].first - sort_even[0].first);
    }
    cout << ans << endl;
}