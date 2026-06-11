#include <iostream>

using namespace std;
const int MAX=3000+1;
string a, b;
int n, m;

int dp[MAX][MAX];
int vis[MAX][MAX];
string ans[MAX][MAX];

int solve(int i, int j){
    if(i >= n || j >= m) return 0;
    int &ret=dp[i][j];
    if(~ret) return ret;
    if(a[i]==b[j]) return ret=1+solve(i+1, j+1);
    ret=max(solve(i+1, j), solve(i, j+1));
    return ret;
}

string build(int i, int j){
    if(i >= n || j >= m) return "";
    string &res=ans[i][j];
    if(vis[i][j]) return res;
    vis[i][j]=1;
    int ret=dp[i][j];
    if(a[i]==b[j]) {
        return res=a[i]+build(i+1, j+1);
    }
    if(solve(i+1, j)==ret){
        res = build(i+1, j);
    } else {
        res =build(i, j+1);
    }
    return res;
}


int main(){

    cin >> a >> b;
    n=a.length(), m=b.length();
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) dp[i][j]=-1;
    int cost=solve(0, 0);
    cout << build(0, 0) << endl;

    return 0;
}
