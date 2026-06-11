#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int a,b,q; cin >> a >> b >> q;
    vector<ll> s(a),t(b);
    rep(i,a) cin >> s[i];
    rep(i,b) cin >> t[i];
    rep(i,q){
        ll x;cin >> x;
        auto Iter1 = upper_bound(ALL(s),x);
        auto Iter2 = upper_bound(ALL(t),x);
        if(Iter1 == s.begin()) {
            if(Iter2 == t.begin()) cout << max(s[0],t[0])-x << endl;
            else if(Iter2 == t.end()) cout << t[0]-s[a-1]+min(t[0]-x,x-s[a-1]) << endl;
            else cout << min(max(*Iter2,s[0])-x,s[0]-*(Iter2-1)+min(s[0]-x,x-*(Iter2-1))) << endl;
        }else if(Iter1 == s.end()){
            if(Iter2 == t.begin()) cout << t[0]-s[a-1]+min(t[0]-x,x-s[a-1]) << endl;
            else if(Iter2 == t.end()) cout << x-min(t[b-1],s[a-1]) << endl;
            else cout << min(x-min(*(Iter2-1),s[a-1]),*Iter2-s[a-1]+min(*Iter2-x,x-s[a-1])) << endl;
        }else{
            if(Iter2 == t.begin()) cout << min(max(*Iter1,t[0])-x,t[0]-*(Iter1-1)+min(t[0]-x,x-*(Iter1-1))) << endl;
            else if(Iter2 == t.end()) cout << min(x-min(t[b-1],*(Iter1-1)),*Iter1-t[b-1]+min(*Iter1-x,x-t[b-1])) << endl;
            else cout << min(min(max(*Iter2,*Iter1)-x,x-min(*(Iter2-1),*(Iter1-1))),min(*Iter2-*(Iter1-1)+min(*Iter2-x,x-*(Iter1-1)),*Iter1-*(Iter2-1)+min(*Iter1-x,x-*(Iter2-1)))) << endl;
        }
    }
}