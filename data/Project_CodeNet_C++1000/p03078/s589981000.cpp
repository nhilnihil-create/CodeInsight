#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,P>
using namespace std;

int main(){
    int x,y,z,k; cin >> x >> y >> z >> k;
    vector<ll> a(x),b(y),c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];
    sort(all(a));
    reverse(all(a));
    sort(all(b));
    reverse(all(b));
    sort(all(c));
    reverse(all(c));
    vector<pair<P,int> > check;
    priority_queue<PP> q;
    q.push(PP(P(a[0]+b[0]+c[0],0),P(0,0)));
    while(k){
        ll de=q.top().first.first;
        int aid=q.top().first.second;
        int bid=q.top().second.first;
        int cid=q.top().second.second;
        q.pop();
        bool exi=false;
        rep(i,check.size()){
            if(check[i].first.first==aid && check[i].first.second==bid && check[i].second==cid){
                exi=true;
                break;
            }
        }
        if(exi) continue;
        pair<P,int> g = make_pair(P(aid,bid),cid);
        check.push_back(g);
        cout << de << endl;
        if(aid!=x-1) q.push(PP(P(a[aid+1]+b[bid]+c[cid],aid+1),P(bid,cid)));
        if(bid!=y-1) q.push(PP(P(a[aid]+b[bid+1]+c[cid],aid),P(bid+1,cid)));
        if(cid!=z-1) q.push(PP(P(a[aid]+b[bid]+c[cid+1],aid),P(bid,cid+1)));
        k--;
    }
return 0;
}
