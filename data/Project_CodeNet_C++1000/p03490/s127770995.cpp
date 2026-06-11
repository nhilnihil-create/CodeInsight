#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define INF (1 << 30) - 1
#define LLINF (1LL << 61) - 1
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    ll x,y,now=0,z=0;
    bool A[4010][20000],B[4010][20000];
  	rep(i,4010)rep(j,20000){
      A[i][j]=0;B[i][j]=0;
    }
    A[0][10000]=1;B[0][10000]=1;
    vector<ll> a,b;
    cin>>s>>x>>y;
    rep(i,(ll)s.size()){
        if(s[i]=='F') now++;
        if(s[i]=='F' && i==(ll)s.size()-1){
            if(z==0){
                a.pb(now);
            } else{
                b.pb(now);
            }
        }
        if(s[i]=='T'){
            if(z==0){
                a.pb(now);
                now=0;
                z=1;
            }
            else{
                b.pb(now);
                now=0;
                z=0;
            }
        }
    }
  	/*
    rep(i,(ll)a.size()){
        cout<<a[i]<<endl;
    }
    cout<<endl;
    rep(i,(ll)b.size()){
        cout<<b[i]<<endl;
    }
    */
    rep(i,(ll)a.size()){
        if(i==0 && s[0]=='F'){
            A[1][a[0]+10000]=1;
          	continue;
        }
        rep(j,20000){
            if(A[i][j]==1){
                A[i+1][j+a[i]]=1;
                A[i+1][j-a[i]]=1;
            }
        }
    }
    rep(i,(ll)b.size()){
        rep(j,20000){
            if(B[i][j]==1){
                B[i+1][j+b[i]]=1;
                B[i+1][j-b[i]]=1;
            }
        }
    }
  	//cout<<A[a.size()][10000+x] <<B[b.size()][10000+y] <<endl;
    if(A[a.size()][10000+x]==1 && B[b.size()][10000+y]==1){
        cout<<"Yes"<<endl;
    } else{
        cout<<"No"<<endl;
    }
    return 0;
}