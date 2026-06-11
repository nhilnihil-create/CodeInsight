#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int n;
int ans = 0;
void dfs(ll cur,int a,int b,int c) {
    if(cur > n) return;
    if(a && b && c) ans++;
    dfs(cur*10+7,1,b,c);
    dfs(cur*10+5,a,1,c);
    dfs(cur*10+3,a,b,1);
    return;
}

int main() {
    cin >> n;
    vector<int>a;
    int cur = 1;
    dfs(0,0,0,0);
    cout << ans << endl;
}