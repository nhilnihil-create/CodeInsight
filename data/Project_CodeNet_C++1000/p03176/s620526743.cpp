#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define sz() size()
#define fr first
#define sc second
#define int long long
#define mp make_pair
#define rc(s) return cout<<s,0
#define rcc(s) cout<<s,exit(0)
using namespace std;

const int nmax=200005;

int n,aib[nmax],a[nmax],b[nmax];

void update(int indx,int val){
    for(int i=indx;i<=n;i+=(i&-i)) aib[i]=max(aib[i],val);
}

int query(int indx){
    int rs=0;
    for(int i=indx;i>=1;i-=(i&-i)){
        rs=max(rs,aib[i]);
    }
    return rs;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++){
        auto it=query(a[i]);
        update(a[i],it+b[i]);
    }
    cout << query(n);
}
