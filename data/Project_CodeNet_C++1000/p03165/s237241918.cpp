#include<bits/stdc++.h>
using namespace std; 
#define all(c) c.begin(),c.end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define tr(container,it) \
for(auto it=container.begin();it!=container.end();++it)
typedef long long ll ; 
typedef vector<int> vi;
#define mod 1000000007

bool first_row_or_column(pair<int,int> p) {
    return p.first == 0 || p.second == 0;
}
int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
  ios::sync_with_stdio(0);
// cin.tie(0);
/* 
int n;
cin>>n;
vi v(n);
REP(i,0,n-1)
cin>>v[i];
vi v2=v;
sort(all(v2));
 */
 string s,t;
 cin>>s>>t;
 vector<vector<pair<int,pair<int,int>>>>dp(s.size()+1,vector<pair<int,pair<int,int>>>(t.size()+1,{0,{0,0}}));
 for(int i=1;i<=s.size();++i){
     for(int j=1;j<=t.size();++j){
         if(s[i-1]==t[j-1])
        {
        dp[i][j]=make_pair(dp[i-1][j-1].first+1,make_pair(i-1,j-1));

        }
        if(dp[i][j].first<dp[i-1][j].first){
            dp[i][j]=make_pair(dp[i-1][j].first,make_pair(i-1,j));
        }
        if(dp[i][j].first<dp[i][j-1].first){
            dp[i][j]=make_pair(dp[i][j-1].first,make_pair(i,j-1));
        }
         
        
     }
 }
  string ans;
 if(s[s.size()-1]==t[t.size()-1])
 ans+=s[s.size()-1];
int i=dp[s.size()][t.size()].second.first;
int j=dp[s.size()][t.size()].second.second;
while(i&&j){
    if(s[i-1]==t[j-1]){
        ans+=s[i-1];
    }
    int i1=i,j1=j;
    i=dp[i1][j1].second.first;
    j=dp[i1][j1].second.second;
}
reverse(all(ans));
cout<<ans;

 
 

    return 0;
}