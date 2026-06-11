#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<P> a(n);
    rep(i, n)cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end(), greater<P>());
    ll sum = 0;
    set<int> t;
    stack<int> stock;
    rep(i, k){
        sum += a[i].first;
        if(t.find(a[i].second) == t.end()){
            t.insert(a[i].second);
        }else{
            stock.push(a[i].first);
        }
    }
    ll s = t.size();
    ll ans = sum + s * s;
    for(int i = k; i < n; i++){
        if(t.find(a[i].second) == t.end()){
            if(!stock.empty()){
                sum -= stock.top();
                sum += a[i].first;
                stock.pop();
                t.insert(a[i].second);
                s++;
                ans = max(ans, sum + s * s);
            }
        }
    }
    cout << ans << endl;
}