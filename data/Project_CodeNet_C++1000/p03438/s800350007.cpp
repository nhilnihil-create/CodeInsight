#include <bits/stdc++.h>
#include <algorithm>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) (x).begin(), (x).end()
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long ll;
 
int main() {
 
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i,n)    cin >> a.at(i);
    rep(i,n)    cin >> b.at(i);
 
    ll ac=0,bc=0;
    rep(i,n) {
        if(a[i]<b[i]) {
            ll c=b[i]-a[i];
            if(c%2==0) {
                ac+=c/2;
            }
            else {
                ac+=((c+1)/2);
                bc++;
            }
        }
        else    bc+=(a[i]-b[i]);
    }
 
    if(ac>=bc)  cout<<"Yes"<<endl;
    else    cout<<"No"<<endl;
 
 return 0;
}