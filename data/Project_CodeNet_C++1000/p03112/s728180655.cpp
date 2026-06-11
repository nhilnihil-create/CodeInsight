#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
int main(){
    ll a,b,q;cin >> a >> b >> q;
    vector<ll> s(a),t(b),x(q);
    for(int i=0;i<a;i++) cin >> s[i];
    for(int i=0;i<b;i++) cin >> t[i];
    for(int i=0;i<q;i++) cin >> x[i];
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    int n=s.size(),m=t.size();
    for(int i=0;i<q;i++){
        ll p1=lower_bound(s.begin(),s.end(),x[i])-s.begin();
        ll SposR=(p1!=n)?s[p1]-x[i]:LINF;
        ll SposL=(p1!=0)?x[i]-s[p1-1]:LINF;
        ll p2=lower_bound(t.begin(),t.end(),x[i])-t.begin();
        ll TposR=(p2!=m)?t[p2]-x[i]:LINF;
        ll TposL=(p2!=0)?x[i]-t[p2-1]:LINF;
        //cout << SposL << " " << SposR << " " << TposL << " " << TposR << endl;
        ll candi1=max(SposL,TposL);
        ll candi2=max(SposR,TposR);
        ll candi3=min(SposL,TposR)*2+max(SposL,TposR);
        ll candi4=min(TposL,SposR)*2+max(TposL,SposR);
        cout << min({candi1,candi2,candi3,candi4}) << endl;
    }
    return 0;
}