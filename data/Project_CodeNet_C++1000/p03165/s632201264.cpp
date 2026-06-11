#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main(){
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
    if(i == 0 || j == 0)
        dp[i][j] = 0;
    else{
    if(s[i-1] == t[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
    else 
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
}
}
}
  
string lcs ;
int i = n, j = m;
while(i > 0 && j > 0){
    if(s[i-1] == t[j-1]){ //cout << i-1 << " " << j-1 << endl;
    lcs += s[i-1]; 
     i-- , j--;
}
else{
    if(dp[i-1][j] > dp[i][j-1]){
    i--;
}
else
    j--;
}
        
}

reverse(lcs.begin(), lcs.end());
cout << lcs;
}


