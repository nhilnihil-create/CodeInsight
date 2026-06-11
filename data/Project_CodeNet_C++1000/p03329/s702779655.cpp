#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
//stoi(s) : string→int stoll(s) :string→longlong
const double PI=3.14159265358979323846;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int dp[1000010];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<1000010;i++){
        dp[i] = INT_INF;
    }
    dp[0] = 0;
    dp[1] = 1;
    for(int i=0;i<=n;i++){
        chmin(dp[i+1],dp[i] + 1);
        for(int j=1;j<=7;j++){
            int q = i + pow(6,j);
            chmin(dp[q],dp[i] + 1 );
        }
        for(int j=1;j<=6;j++){
            int q = i + pow(9,j);
            chmin(dp[q],dp[i] + 1);
        }
    }
    cout << dp[n] << endl;
}