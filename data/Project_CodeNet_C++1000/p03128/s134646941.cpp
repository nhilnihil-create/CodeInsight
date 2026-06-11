#include <bits/stdc++.h>
using namespace std;

const vector<int> match = {0,2,5,5,4,5,6,3,7,6};

void chmax(string &a, string b){
    if(a == "-") a = b;
    else if(a.size() < b.size()) a = b;
    else if(a.size() == b.size()){
        if(a < b) a = b;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for(int i=0; i<m; i++){
        cin >> a[i];
    }

    vector<string> dp(20000, "-");// dp[0] = "-", dp[1] = "-", dp[2] = "-", ...
    dp[0] = "";

    for(int i=0; i<=n; i++){
        if(dp[i] == "-") continue;
        for(auto num : a){
            chmax(dp[i + match[num]], 
                  dp[i] + (char)('0' + num)// joining : string + char
            );
        }
    }
    cout << dp[n] << endl;
    return 0;
}