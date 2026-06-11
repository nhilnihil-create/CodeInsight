#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mod = 1000000007;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

void prvec(vector<ll> vec){ //for debug
    ll n = vec.size();
    cout << "------------------------------------\n" ;
    rep(i,n) cout << i << " " << vec.at(i) << "\n";
    cout << "------------------------------------\n" ;
}

void pr2d(vector<vector<ll>> vec){ // for debug
    ll h = vec.size();
    ll w = vec.at(0).size();
    cout << "------------------------------------\n" ;
    rep(i,h){
        rep(j,w){
            cout << vec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
    cout << "------------------------------------\n" ;
}

int main(){
    ll a,b,q; cin >> a >> b >> q;
    vector<ll> s(a),t(b);
    rep(i,a) cin >> s.at(i);
    rep(i,b) cin >> t.at(i);
    while(q--){
        ll y; cin >> y;
        ll x = y;
        ll rab =LINF,lab =LINF,rba = LINF,lba = LINF;
        //a->b
        auto itst = lower_bound(s.begin(),s.end(),x);
        ll xx = itst - s.begin();
        if(itst!=s.begin()){
            lab = abs(x - s.at(xx-1));
            x = s.at(xx-1);
            itst =lower_bound(t.begin(),t.end(),x);
            xx = itst - t.begin();
            if(itst==t.begin()){
                lab += abs(x-*itst);
            }else if(itst==t.end()){
                itst--;
                lab += abs(x-*itst);
            }else{
                lab += min(abs(x-t.at(xx-1)), abs(x-t.at(xx)));
            }
        }
        x = y;
        itst = lower_bound(s.begin(),s.end(),x);
        xx = itst - s.begin();
        if(itst!=s.end()){
            rab = abs(x - s.at(xx));
            x = s.at(xx);
            itst =lower_bound(t.begin(),t.end(),x);
            xx = itst - t.begin();
            if(itst==t.begin()){
                rab += abs(x-*itst);
            }else if(itst==t.end()){
                itst--;
                rab += abs(x-*itst);
            }else{
                rab += min(abs(x-t.at(xx-1)), abs(x-t.at(xx)));
            }
        }
        x = y;
        itst = lower_bound(t.begin(),t.end(),x);
        xx = itst - t.begin();
        if(itst!=t.begin()){
            lba = abs(x - t.at(xx-1));
            x = t.at(xx-1);
            itst =lower_bound(s.begin(),s.end(),x);
            xx = itst - s.begin();
            if(itst==s.begin()){
                lba += abs(x-*itst);
            }else if(itst==s.end()){
                itst--;
                lba += abs(x-*itst);
            }else{
                lba += min(abs(x-s.at(xx-1)), abs(x-s.at(xx)));
            }
        }
        x = y;
        itst = lower_bound(t.begin(),t.end(),x);
        xx = itst - t.begin();
        if(itst!=t.end()){
            rba = abs(x - t.at(xx));
            x = t.at(xx);
            itst =lower_bound(s.begin(),s.end(),x);
            xx = itst - s.begin();
            if(itst==s.begin()){
                rba += abs(x-*itst);
            }else if(itst==s.end()){
                itst--;
                rba += abs(x-*itst);
            }else{
                rba += min(abs(x-s.at(xx-1)), abs(x-s.at(xx)));
            }
        }
        cout << min(min(rab,lab),min(rba,lba)) << endl;
    }
}