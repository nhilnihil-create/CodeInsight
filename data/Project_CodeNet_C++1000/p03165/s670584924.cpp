#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
vector <char> str;
int dp[3005][3005];
string s, t;
int slen, tlen;
int main(){
    getline(cin, s);
    getline(cin, t);
    slen = s.length();
    tlen = t.length();
    for(int i = 0 ; i<= tlen ; i++){
        for(int j = 0 ; j<=slen ; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }
            if(t[i-1] == s[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = tlen, j = slen;
    while(i > 0 && j > 0){
        if(t[i-1] == s[j-1]){
            str.push_back(t[i-1]);
            i--;
            j--;
            
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else j--;
        }
    }
    reverse(str.begin(), str.end());
    for(auto i : str) cout << i;
}