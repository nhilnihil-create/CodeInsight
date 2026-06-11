#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double pi = 3.14159265358979;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;
    vector<pair<pair<ll,ll>, ll>> x(m);
    for (ll i = 0; i < m; i++){
        cin >> x[i].first.first >> x[i].first.second;
        x[i].second = i;
    }

    sort(x.begin(), x.end());

    ll c = 1;
    x[0].first.second = 1;

    for (ll i = 1; i < m; i++){
        if (x[i].first.first == x[i-1].first.first){
            c++;
        }
        else{
            c = 1;
        }
        x[i].first.second = c;
    }

    /*for (ll i = 0; i < m; i++){
        cout << x[i].first.first << " " << x[i].first.second << " " <<  x[i].second << endl;
    }*/

    vector<pair<ll,string>> y(m);
    for (ll i = 0; i < m; i++){
        y[i].first = x[i].second;
        string s = to_string(x[i].first.first);
        rep(j,(6-s.size())){
            y[i].second.push_back('0');
        }
        rep(j,s.size()){
            y[i].second.push_back(s[j]);
        }

        string t = to_string(x[i].first.second);
        rep(j,(6-t.size())){
            y[i].second.push_back('0');
        }
        rep(j,t.size()){
            y[i].second.push_back(t[j]);
        }

    }

    sort(y.begin(), y.end());

    for (ll i = 0; i < m; i++){
        cout << y[i].second << endl;
    }

}