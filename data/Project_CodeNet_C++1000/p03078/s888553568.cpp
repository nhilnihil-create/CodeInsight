#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll X, Y, Z, K, ans=0, tmp=0;
vector<ll> Xs, Ys, Zs, XYs;

signed main(){
    cin >> X >> Y >> Z >> K;
    for(int i=0;i<X;i++) {
        ll a;
        cin >> a;
        Xs.push_back(a);
    }
    for(int i=0;i<Y;i++) {
        ll a;
        cin >> a;
        Ys.push_back(a);
    }
    for(int i=0;i<Z;i++) {
        ll a;
        cin >> a;
        Zs.push_back(a);
    }
    for(int i=0;i<X;i++) {
        for(int j=0;j<Y;j++) {
            XYs.push_back(Xs[i]+Ys[j]);
        }
    }
    sort(XYs.begin(), XYs.end());
    priority_queue<pair<ll,ll>> PQ;
    for(int i=0;i<Z;i++) {
        PQ.push(make_pair(XYs.back()+Zs[i],XYs.size()-1));
    }
    int i=0;
    while(i!=K) {
        pair<ll,ll> p = PQ.top();
        tmp = p.first;
        PQ.pop();
        if(p.second>=1) PQ.push(make_pair(XYs[p.second-1]+tmp-XYs[p.second],p.second-1));
        cout << tmp << endl;
        i++;
    }
    return 0;
}