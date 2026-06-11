#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ipair;
typedef pair<ll, ll> llpair;

/*
    Author: Koushik Sahu
    Created: 09 September 2020 Wed 12:17:30
*/

string s, t;
int dp[3001][3001];
char ans[3001][3001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int j=0; j<=n; j++) dp[0][j] = 0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            ans[i][j] = '.';
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans[i][j] = 'M';
            }else{
                if(dp[i-1][j]>=dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    ans[i][j] = 'U';
                }else{
                    dp[i][j] = dp[i][j-1];
                    ans[i][j] = 'L';
                }
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string answer = "";
    int p=n, q=m;
    while(p>=0 && q>=0 && ans[p][q]!='.'){
        if(s[p-1]==t[q-1]) answer += s[p-1];
        if(ans[p][q]=='U'){
            p -= 1;
        }else if(ans[p][q]=='L'){
            q -= 1;
        }else{
            p -= 1;
            q -= 1;
        }
    }
    reverse(answer.begin(), answer.end());
    cout<<answer<<"\n";
    return 0;
}