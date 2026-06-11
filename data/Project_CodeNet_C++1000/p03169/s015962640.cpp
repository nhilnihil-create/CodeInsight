#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define M1 (ll)1000000007
#define M2 (ll)998244353
#define Pi 3.141592653
#define exp 2.71828
#define ll long long
#define ull unsigned long long
#define pi pair<int,int>
#define pl pair<ll,ll> 
#define vi vector<int>
#define vl vector<ll>
#define di deque<int>
#define dl deque<ll>
#define dii deque<pi>
#define dll deque<pl>
#define vvi vector<vi>
#define vvl vector<vl>
#define vii vector<pi>
#define vll vector<pl>
#define pb push_back
#define pp pop_back
#define pf push_front
#define pt pop_front
#define mp make_pair
#define in insert
#define er erase
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define rp(i,a,b) for(int i=a;i<b;i++)
#define rpt(i,a,b,t) for(int i=a;i<b&&t<1;i++)
#define rep(i,n) for(int i = 0 ; i<n ; i++)
#define rept(i,n,t) for(int i = 0 ; i<n&&t<1 ; i++)
#define repr(i,n) for(int i = n-1 ; i>=0 ; i--)
#define reprt(i,n,t) for(int i=n-1;i>=0&&t<1;i--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define SORT(v) sort(v.begin(),v.end())
int main() {
    int n;
    cin>>n;
    int x;
    int c[4]={0};
    for(int i=0;i<n;++i) cin>>x,++c[x];
    double t1,t2;
    double dp[n+1][n+1][n+1];
    dp[0][0][0]=0;
    n = (double)n;
    for(int i=0;i<c[3]+1;++i){
        for(int j=0;j<c[2]+c[3]+1;++j){
            for(int k=0;k<(int)n+1 && i+j+k<=(int)n;++k){
                if(i+j+k == 0 || i+j+k>(int)n) continue;
                t1 = i+j+k;
                t2 = 0;
                dp[i][j][k] = n/t1;
                t2 += (i!=0)?(((double)i/n)*dp[i-1][j+1][k]):0;
                t2 += (j!=0)?(((double)j/n)*dp[i][j-1][k+1]):0;
                t2 += (k!=0)?(((double)k/n)*dp[i][j][k-1]):0;
                t2 += 1;
                dp[i][j][k] *= t2;
            }
        }
    }
    cout<<setprecision(10)<<dp[c[3]][c[2]][c[1]];
}
