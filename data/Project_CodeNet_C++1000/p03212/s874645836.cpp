#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int n;
int ans = 0;
void dfs(vector<int>&a) {
    if(a.size()==10) return;
    int now = 0;
    
    if(a.size()>=3) {
        int cur = pow(10,a.size()-1);
        rep(i,a.size()) {
            now += a[i]*cur;
            cur /= 10;
        }
    }
    bool ok1 =false;
    bool ok2 = false;
    bool ok3 = false;
    rep(i,a.size()) {
        if(a[i]==3)ok1 = true;
        if(a[i]==5)ok2 = true;
        if(a[i]==7)ok3 = true;
    }
    if(now<=n && ok1 && ok2 && ok3) ans++;
    for(int i = 3;i<=7;i += 2) {
        a.push_back(i);
        dfs(a);
        a.pop_back();
    }
    return;
}

int main() {
    cin >> n;
    vector<int>a;
    int cur = 1;
    dfs(a);
    cout << ans << endl;
}