#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


vector<int> memo; 
int rec(int n) {
    if(n==0) return 0;
    if(memo[n] != -1) return memo[n];
    int res = n;
    for(int pow6 = 1;pow6<=n;pow6 *= 6) {
        chmin(res,rec(n-pow6)+1);
    }
    for(int pow9 = 1;pow9<=n;pow9 *= 9) {
        chmin(res,rec(n-pow9)+1);
    }
    return memo[n] = res;
}

int main() {
    int n;
    cin >> n;
    memo.resize(n+10000);
    rep(i,n+10000) memo[i] = -1;
    cout << rec(n) << endl;
}    