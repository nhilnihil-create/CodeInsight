#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> lP;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    int n; cin>>n;
    vector<P> red;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        P v=P(a,b);
        red.push_back(v);
    }
    vector<P> blue;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        P v=P(a,b);
        blue.push_back(v);
    }

    sort(red.begin(),red.end());
    sort(blue.begin(),blue.end());
    vector<bool> id(n,true);

    rep(i,n){
        P v=blue[i];
        int maxy=-1;
        int maxj=-1;
        rep(j,n){
            P w=red[j];
            if(v.first>w.first&&v.second>w.second&&id[j]){
                if(maxy<w.second){
                    maxy=w.second;
                    maxj=j;
                }
            }
        }
        if(maxy==-1) continue;
        else id[maxj]=false;
    }
    int ans=0;
    rep(i,n){
        if(!id[i]) ans++;
    }
    cout<<ans<<endl;

}