#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n,m;cin>>n>>m;
    vector<char>match(8);
    rep(i,m){
        char a;cin>>a;
        if(a=='1')match[2]='1';
        if(a=='2')match[5]=max(match[5],'2');
        if(a=='3')match[5]=max(match[5],'3');
        if(a=='4')match[4]='4';
        if(a=='5')match[5]=max(match[5],'5');
        if(a=='6')match[6]=max(match[6],'6');
        if(a=='7')match[3]='7';
        if(a=='8')match[7]='8';
        if(a=='9')match[6]=max(match[6],'9');
    }
    vector<string>dp(10010);
    REP(i,1,n+1){
        rep(j,8){
            if(match[j]){
                if(i-j>=0){
                    if(dp[i-j].size()>0||i-j==0){
                    string a="";
                    a+=match[j];
                    a+=dp[i-j];
                    if(a.size()>dp[i].size())dp[i]=a;
                    if(a.size()==dp[i].size()&&dp[i]<a)dp[i]=a;
                    }
                }
            }
        }
    }
    cout<<dp[n]<<endl;
}