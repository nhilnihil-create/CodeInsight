#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const ll INF = +10010010000;

typedef pair<ll,ll> P;
const ll MO = 1000000007;

int main(){
    // map<int,int> mp;
    int n;
    cin >> n;
    vector<ll>x(n),a(n);
    rep(i,n)cin >> x[i];
    a = x;
    sort(x.begin(),x.end());
    // rep(i,n){
    //     mp[x[i]]++;
    // }
    int mid = (n/2);
    rep(i,n){        
        if(a[i]<x[mid]){
            cout<<x[mid]<<endl;
        }else{
            cout << x[mid-1] << endl;
        }
    }
    return 0;
}