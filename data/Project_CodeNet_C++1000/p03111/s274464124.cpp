#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int n;
int A,B,C;
vector<int>l;
const int INF = 1001001001;
int dfs(int i,int a,int b,int c) {
    int res = INF;
    if(i==n) {
        int res = 0;
        if(a && b && c) {
            res += abs(a-A)+abs(b-B)+abs(c-C);
        } else res = INF;
        return res;
    }
    int res1,res2,res3,res4;
    if(a==0) res1 = dfs(i+1,a+l[i],b,c);
    else  res1 = dfs(i+1,a+l[i],b,c) + 10;

    if(b==0) res2 = dfs(i+1,a,b+l[i],c);
    else  res2 = dfs(i+1,a,b+l[i],c) + 10;

    if(c==0) res3 = dfs(i+1,a,b,c+l[i]);
    else  res3 = dfs(i+1,a,b,c+l[i]) + 10;
    res4 = dfs(i+1,a,b,c);
    res = min({res1,res2,res3,res4});
    return res;
}

int main() {
    cin >> n >> A >> B >> C;
    l.resize(n);
    rep(i,n) cin >> l[i];
    int ans = dfs(0,0,0,0);
    cout << ans << endl;
}