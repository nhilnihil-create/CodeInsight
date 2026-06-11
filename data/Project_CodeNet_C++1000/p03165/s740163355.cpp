#include <bits/stdc++.h>
#define ll long long int
#define F(i,j,k,in) for(int i=j;i<k;i+=in)
#define DF(i,j,k,in) for(int i=j;i>=k;i-=in)
#define feach(it,l) for (auto it = l.begin(); it != l.end(); ++it)
#define fitr(it,it1,itr2) for(auto it=itr1;it!=itr2;++it)
#define fall(a) a.begin(),a.end()
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define eq equal_range
#define fs first
#define ss second
#define ins insert
#define mkp make_pair
#define endl "\n"
using namespace std;
typedef vector<ll> vll;
typedef vector<int> vin;
typedef vector<char> vch;
typedef vector<string> vst;
typedef vector<vector<ll>> vvll;
typedef vector<vector<int,int>> vvin;
typedef vector<pair<ll,ll>> vpll;
typedef vector<pair<int,int>> vpin;
typedef set<ll> sll;
typedef set<int> sint;
typedef set<char> sch;
typedef set<string> sst;
typedef queue<ll> qll;
typedef priority_queue<ll> pqll;
typedef queue<int> qin;
typedef priority_queue<int> pqin;
typedef map<ll,ll> mpll;
typedef map<int,int> mpin;
typedef pair<ll,ll> pll;
typedef pair<int,int> pin;
const ll MOD=1000000007;
const long double PI=3.1415926535897932384626433832795;
ll pwr(ll b,ll p){ll res=1;while(p){if(p&1) {res*=b; p--;}else{b*=b; p>>=1;}}return res;}
const int maxn=3e3+1;
int dp[maxn][maxn];
int choice[maxn][maxn];
int main()
{
ios_base::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL);
string s, t;
cin>>s>>t;
vch ans;
F (i,1,(int)s.length()+1,1) {
  F (j,1,(int)t.length()+1,1) {
    // dp[i][j]= lcs of string  ending at index i and j !
    // Not picking current element 
    if (dp[i][j-1] > dp[i-1][j]) {
      dp[i][j]= dp[i][j-1];
      choice[i][j]=1;
    }
    else {
      dp[i][j]=dp[i-1][j]; 
    }
    if (s[i-1]==t[j-1]) {
      if (dp[i-1][j-1]+1 > dp[i][j]) {
        dp[i][j]=dp[i-1][j-1]+1;
        choice[i][j]=2;
      }
    }

    }
}
int i=(int)s.length() , j= (int)t.length();
while (i>=1 && j>=1) {
    if (choice [i][j]==2) { ans.pb(s[i-1]); --i; --j;} 
    else if (choice[i][j]==1)  {--j;}
    else --i;
}
reverse (fall(ans));
feach (it,ans) cout<<*it;
return 0;
}

