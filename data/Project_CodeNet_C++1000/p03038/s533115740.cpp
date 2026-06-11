#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int ta;
        cin >> ta;
        a.emplace_back(ta);
    }
    sort(a.begin(),a.end());
    vector<pair<int,int>> cb(m);
    for(int i = 0; i < m; i++) {
        cin >> cb[i].second >> cb[i].first;
    }
    sort(cb.rbegin(),cb.rend());

    int idx=0;
    bool cont=false;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < cb[i].second; j++) {
            a.emplace_back(cb[i].first);
            idx++;
            if(idx>n){
                cont=true;
                break;
            }
        }
        if(cont) break;
    }

    sort(a.rbegin(),a.rend());
    ll count=0;
    for(int i = 0; i < n; i++) {
        count+=a[i];
    }
    cout << count << "\n";

    return 0;
}