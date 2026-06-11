#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n;
    cin >> n;
    vector<pii> vp;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({a+b, a});
    }
    sort(vp.rbegin(), vp.rend());
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (i%2)*(-vp[i].first)+vp[i].second;
    } 
    cout << ans << endl;
    return 0;
}