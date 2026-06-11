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
using namespace std;
bool cmp(pair<int,int> i,pair<int,int> j){
    return i.first<j.first;
}
int main() {
    fast
    string s,t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    int lcs[n+1][m+1];
    for(int i=0;i<n+1;++i) for(int j=0;j<m+1;++j) lcs[i][j]=0;
    for(int i=1;i<n+1;++i){
        for(int j=1;j<m+1;++j){
            if(s[i-1]==t[j-1]) lcs[i][j] = lcs[i-1][j-1]+1;
            else lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    string result = "";
    int xp=n,yp=m;
    while(result.length()<lcs[n][m]){
        if(s[xp-1]==t[yp-1]) result=s[xp-1]+result,--xp,--yp;
        else{
            if(lcs[xp-1][yp]==lcs[xp][yp]) --xp;
            else --yp;
        }
    }
    cout<<result;
}
