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
    vector<bool> p(55556,true);
    p[1] = false;
    for (int i=2;i<=55555;i++){
        for (int j=i*2;j<=55555;j+=i){
            p[j] = false;
        }
    }
    vector<int> ans;
    int num = 0;
    for (int i=2;i<=55555;i++){
        if (p[i] && i%5==1) {
            ans.push_back(i);
            num++;
        }
        if (num == N) break;
    }
    for (int i=0;i<ans.size();i++) cout << ans[i] << "\n";
}