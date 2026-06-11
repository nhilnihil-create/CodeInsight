#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    set<pair<int,int>> p;
    if (N%2==0){
        for (int i=1;i<=N/2;i++){
            p.insert(make_pair(i,N+1-i));
        }
    } else {
        for (int i=1;i<=N/2;i++){
            p.insert(make_pair(i,N-i));
        }
    }
    vector<pair<int,int>> ans;
    for (int i=1;i<N;i++){
        for (int j=i+1;j<=N;j++){
            if (p.find(make_pair(i,j)) == p.end()){
                ans.emplace_back(i,j);
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i=0;i<ans.size();i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}