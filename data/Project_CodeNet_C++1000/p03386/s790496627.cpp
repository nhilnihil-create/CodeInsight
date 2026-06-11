#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int a,b,k;
    cin >> a >> b >> k;
    vector<int>ans;
    for(int i = a;i<a+k;i++) {
        ans.push_back(i);
    }
    for(int i = b;i>b-k;i--) {
        ans.push_back(i);
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    rep(i,ans.size()) {
        if(ans[i]<a) continue;
        if(ans[i]>b) break;
        cout << ans[i] << endl;
    }
    
}