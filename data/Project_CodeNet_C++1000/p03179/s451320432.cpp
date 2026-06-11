#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(i,s,e) for(int i=s;i<=e;i++)
#define endl '\n'
#define debug(P) cout<<#P<<" = "<<P<<endl;
#define pb push_back
#define FILE freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);


using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int NAX = 3002;

int dp[NAX][NAX];    //prefix of 1..i such that j is last number

void add(int &x, int y){
    x += y;
    if(x > MOD) x -= MOD;
    if(x < 0) x += MOD;
}

int main(){
    //inp_out_work
    //FILE
    int n;
    string s;
    cin>>n;
    cin>>s;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++){
        vector<int> cpy(i);
        cpy[0] = dp[i-1][0];

        for(int j = 1; j < i; j++){
                cpy[j] = cpy[j-1] + dp[i-1][j];
                if(cpy[j]>MOD)cpy[j] -= MOD;
        }

        for(int j = 1; j <= i; j++){
            if(s[i-2] == '<'){
                add(dp[i][j], cpy[j-1]);
            }
            else{
               add(dp[i][j], cpy[i-1]-cpy[j-1]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)add(ans, dp[n][i]);
    cout<<ans<<endl;
}
