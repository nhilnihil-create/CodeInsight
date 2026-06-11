#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 10000000000099ll
#define mod 1000000007
#define MAX 3000
int dp[MAX+1][MAX+1];

string printLcs(string s, string t, int n, int m){
    int i= n, j=m;
    string res="";
    while(i>0 && j>0){
        if(s[i]==t[j]){
            res.push_back(s[i]);
            i--;j--;
        }
        else{
            if(dp[i][j-1] > dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve(string s, string t, int n, int m)
{
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(s[i]==t[j]) dp[i][j]= 1+ dp[i-1][j-1];
            else {
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}

int main()
{
    FASTIO;
    string s, t;
    cin>>s>>t;
    s=" "+ s;
    t=" "+ t;
    int n= s.length();
    int m= t.length();
    memset(dp, 0, sizeof dp);
    solve(s, t, n, m);
    cout<<printLcs(s, t, n-1, m-1);
    return 0;
}


