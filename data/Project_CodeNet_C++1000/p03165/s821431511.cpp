#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const ll mod=1e9+7;

const int N=3001;
int dp[N][N];
string s,t;

int go(int pos1, int pos2){
    if(pos1==s.size() || pos2==t.size()) return 0;
    if(dp[pos1][pos2]!=-1)
        return dp[pos1][pos2];
    int ans=0;
    ans=max(0,max(go(pos1,pos2+1),go(pos1+1,pos2)));
    if(s[pos1]==t[pos2])
        ans=max(ans,1+go(pos1+1,pos2+1));
    return dp[pos1][pos2]=ans;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    cin>>s>>t;
    for(ll i=0;i<N;i++)
        for(ll j=0;j<N;j++)
            dp[i][j]=-1;
    ll z=go(0,0);
    //cout<<z;
    ll n=s.size(), m=t.size();
    ll i=0,j=0;
    string ans;
    while(i<n && j<m){
        if(s[i]==t[j]){
            ans+=s[i];
            i++,j++;
        }
        else if(dp[i+1][j]>dp[i][j+1])
            i++;
        else
            j++;
    }
    cout<<ans;

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}