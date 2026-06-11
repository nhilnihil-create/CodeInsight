#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<int>> Graph;

int main() {
    map<string,int> mp;
    int n,m;
    cin >> n;
    string s;
    rep(i,n){
        cin >> s;
        mp[s]++;
    }
    cin >> m;
    rep(i,m){
        cin >> s;
        mp[s]--;
    }
    int ans=0;
    for(auto i : mp){
        ans = max(ans,i.second);
    }
    cout << ans << endl;  
}