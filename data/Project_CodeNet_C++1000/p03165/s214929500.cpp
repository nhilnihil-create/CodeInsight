#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,pair<int,char>>
#define sorted(a_1) sort(a_1.begin(),a_1.end())
#define rsorted(a_1) sort(a_1.rbegin(),a_1.rend())
#define t1(a_1) cout<<a_1<<endl;
#define t2(a_1) for(auto it_test : a_1) cout<<it_test<<" ";


const int MAX = 1000001;
vector<long long >isprime(MAX , true); 
vector<long long >prime; 
vector<long long >SPF(MAX); 
void Seive(int N) 
{ 
    isprime[0] = isprime[1] = false ; 
   
    for (long long int i=2; i<N ; i++) 
    { 
        if (isprime[i]) 
        { 
            prime.push_back(i);  
            SPF[i] = i; 
        } 
  
        for (long long int j=0; j < (int)prime.size() && i*prime[j] < N && prime[j] <= SPF[i]; j++) 
        { 
            isprime[i*prime[j]]=false; 
   
            SPF[i*prime[j]] = prime[j] ; 
        } 
    } 
} 

ll expo(ll a, ll b, ll m) 
{ 
    if (b == 0) 
        return 1; 
    ll p = expo(a, b / 2, m) % m; 
    p = (p * p) % m; 
  
    return (b % 2 == 0) ? p : (a * p) % m; 
} 

void lcs(string& s1, string& s2){
    int n = s1.length();
    int m = s2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    int index = dp[n][m];
    char com[index+1];
    int i = n,j=m;
    com[index]='\0';
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            com[index-1] = s1[i-1];
            i--;
            j--;index--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<com;
}
void solve(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    lcs(s1,s2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--){
        solve();
    }

return 0;
}