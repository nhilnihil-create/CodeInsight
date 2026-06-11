#include <bits/stdc++.h>

using namespace std;

int solve(string &s, string &t, vector<vector<int>> &pos, vector<vector<int>> &dp, int m, int n){
    if(m < 0 || n < 0){
        return 0;
    }
    if(dp[m][n] != -1){
        return dp[m][n];
    }
    if(s[m] == t[n]){
        pos[m][n] = 0;
        return dp[m][n] = 1 + solve(s, t, pos, dp, m-1, n-1);
    }
    else{
        if(solve(s, t, pos, dp, m-1, n) > solve(s, t, pos, dp, m, n-1)){
            pos[m][n] = 1;
            return dp[m][n] = solve(s, t, pos, dp, m-1, n);
        }
        else{
            pos[m][n] = 2;
            return dp[m][n] = solve(s, t, pos, dp, m, n-1);
        }
    }

}

string print(string &s, string &t, int m, int n, vector<vector<int>> &pos){
    if(m < 0 || n < 0){
        return "";
    }
    if(pos[m][n] == 0){
        string temp = print(s, t, m-1, n-1, pos);
        temp.push_back(s[m]);
        return temp;
    }
    else if (pos[m][n] == 1){
        return print(s, t, m-1, n, pos);
    }
    else{
        return print(s, t, m, n-1, pos);
    }
}

int main(){
    string s, t;
    cin>>s>>t;
    vector<vector<int>> pos(s.length(), vector<int> (t.length(), -1));
    vector<vector<int>> dp(s.length(), vector<int> (t.length(), -1));
    solve(s, t, pos, dp, s.size()-1, t.size()-1);
    cout<<print(s, t, s.size()-1, t.size()-1, pos);
    return 0;
}