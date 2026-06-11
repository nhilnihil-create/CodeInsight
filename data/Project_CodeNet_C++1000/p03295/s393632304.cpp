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
    vector<pair<int,int>> ba(m);
    for(int i = 0; i < m; i++) {
        cin >> ba[i].second >> ba[i].first;
    }
    sort(ba.begin(),ba.end());
    int prev=0;
    int cnt=0;
    for(int i = 0; i < m; i++) {
        if(ba[i].second>prev){
            prev=ba[i].first-1;
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}