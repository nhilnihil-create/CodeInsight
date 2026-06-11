#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll K, ans=0, tmp=0;
vector<ll> A;

signed main(){
    cin >> K;
    for(int i=0;i<K;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    if(A.back()!=2) {
        cout << -1 << endl;
        return 0;
    }
    A.pop_back();
    ll minv = 2;
    ll maxv = 3;
    while(!A.empty()) {
        tmp = A.back();
        A.pop_back();
        minv = minv+tmp-1;
        minv = minv-minv%tmp;
        maxv = maxv-maxv%tmp;
        //cout << minv << " 1 " << maxv << endl;
        if(minv>maxv) {
            cout << -1 << endl;
            return 0;
        }
        maxv += tmp-1;
        //cout << minv << " 2 " << maxv << endl;
    }
    cout << minv << " " << maxv << endl;
    return 0;
}