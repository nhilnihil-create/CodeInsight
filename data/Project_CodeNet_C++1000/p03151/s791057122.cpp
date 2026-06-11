#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> b[i];
    ll sum=0;
    ll num=0;
    rep(i,0,n){
        if(b[i]>a[i]) {
            sum+=b[i]-a[i];
            num++;
        }
        if(a[i]>b[i]){
            c.push_back(a[i]-b[i]);
        }
    }
    sort(c.begin(),c.end(),greater<int>());
    if(sum>0){
        for(int i=0;i<c.size();i++){
            sum-=c[i];
            num++;
            if(sum<1) break;
        }
    }
    if(sum>0) cout << -1 << endl;
    else cout << num << endl;
    return 0;
}