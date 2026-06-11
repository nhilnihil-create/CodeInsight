#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<pair<ll, pair<ll, ll>>> A;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll x, y, h;
        cin >> x >> y >> h;
        A.push_back(make_pair(h, make_pair(x, y)));
    }
    sort(A.begin(), A.end());
    pair<ll, pair<ll, ll>> pp = A.back();
    for(int x1=0;x1<=100;x1++) {
        for(int y1=0;y1<=100;y1++) {
            ll flag=0;
            ll h = pp.first+abs(x1-pp.second.first)+abs(y1-pp.second.second);
            for(int i=0;i<N-1;i++) {
                pair<ll, pair<ll, ll>> pp1 = A[i];
                if(pp1.first==0) {
                    if(h - abs(x1-pp1.second.first) - abs(y1-pp1.second.second)>0) flag=1;
                } 
                else {
                    if(h - abs(x1-pp1.second.first) - abs(y1-pp1.second.second)!=pp1.first) flag=1;
                }
            }
            if(!flag) cout << x1 << " " << y1 << " " << h << endl;
        }
    }
    return 0;
}