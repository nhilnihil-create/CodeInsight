#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const ll mod=pow(10,9)+7;
const ll INF=pow(2,31)-1;
typedef pair<int,int> P;
typedef vector<int> vi;

ll gcd(ll a,ll b){
    ll v0=a,v1=b,v2=a%b;
    while(v2!=0){
        v0=v1;
        v1=v2;
        v2=v0%v1;
    }
    return v1;
}

ll lcm(ll a,ll b){
    return (a*b/gcd(a,b));
}

int MAX_N=200000;
int MAX_M=200000;

int main(){
    ios::sync_with_stdio(false);
    int n,m;
    int d[MAX_N],t[MAX_M];
    map<int,int> mpd,mpt;
    cin >> n;
    rep(i,n){
        cin >> d[i];
    }
    cin >> m;
    rep(i,m){
        cin >> t[i];
    }
    rep(i,n){
        mpd[d[i]]++;
    }
    rep(i,m){
        mpt[t[i]]++;
    }
    rep(i,m){
        int x=t[i];
        if(mpt[x]>mpd[x]){
            cout << "NO" <<endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}