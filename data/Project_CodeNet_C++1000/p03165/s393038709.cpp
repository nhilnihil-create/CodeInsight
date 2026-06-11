//




#include <bits/stdc++.h>
using namespace std;


#define spdio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define pp pop_back()
#define pf push_front
#define ppf pop_front()
#define ff first
#define ss second
#define mp make_pair
#define fr(i,j,n) for(ll i=j; i<n; i++)
#define rfr(i,j,n) for(ll i=n-1; i>=j; i--)
#define pll pair<ll,ll>
#define plb pair<ll,bool>
#define psl pair<string,ll>
#define psb pair<string,bool>
#define srt(v) sort((v).begin(),(v).end())
#define ub(v,val) upper_bound((v).begin(),(v).end(),(val))-(v).begin()
#define lb(v,val) lower_bound((v).begin(),(v).end(),(val))-(v).begin()


typedef long double ld;
typedef long long int ll;


//getline(cin,string);
const ll inf = (ll) 1e18 + 19;
const ll mod = (ll) 1e9  +  7;




void cazz() {
    ll t=1,i=0,j,n;
    //cin>>t;
    while(t--) {
        string s1,s2;
        cin>>s1>>s2;
        vector <vector <ll> > dp(s1.length()+1,vector <ll> (s2.length()+1));
        //lcs(dp,s1,s2,0,0);
        rfr(i,0,s1.length()) {
            rfr(j,0,s2.length()) {
                if(s1[i]==s2[j]) dp[i][j]=dp[i+1][j+1]+1;
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        i=j=0;
        string s="";
        while(i<s1.length() && j<s2.length()) {
            if(s1[i]==s2[j]) {
                s+=s1[i];
                i+=1;
                j+=1;
            }
            else if(dp[i+1][j]>dp[i][j+1]) i+=1;
            else j+=1;
        }
        cout<<s<<"\n";
    }
}




int main() {
    spdio;
	cazz();
	return 0;
}
