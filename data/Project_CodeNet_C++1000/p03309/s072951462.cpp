#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;


int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> b(n);
    for(int i = 1 ; i<=n;++i){
        b[i-1]=a[i-1]-i;
    }
    sort(b.begin(),b.end());
    ll mean;
    if(b.size()%2==1) mean = (b.size()-1)/2;
    else mean = b.size()/2;

    ll ans = 1<<20;
    ll count = 0;
    rep(i,n){
        count+=abs(b[i]-b[mean]);
    }
    cout << count << endl;


}