#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int dp[310][310][310];


int rec(int l, int r, int k, string &S){
    if(dp[l][r][k] >= 0) 
        return dp[l][r][k];
    int res = 0;
    if(l == r){
        res = 1;
    }
    else if(l > r){
        res = 0;
    }
    else{
        if(S[l] == S[r]){
            res = max(res, rec(l + 1, r - 1, k, S) + 2);
        }
        else{
            if(k - 1 >= 0){
                res = max(res, rec(l + 1, r - 1, k - 1, S) + 2);
                res = max(res, rec(l + 1, r - 1, k - 1, S) + 2);
            }
        }
        res = max(res, rec(l + 1, r, k, S));
        res = max(res, rec(l, r - 1, k, S));
    }
    return dp[l][r][k] = res;
}


int main(){

    string S;
    int K;
    cin >> S;
    cin >> K;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, (int)S.size() - 1, K, S) << endl;
    

    return 0;
}
