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

    string s,t;
    cin >> s >> t;
    ll sn = s.size();
    ll tn = t.size();

    if (sn < tn){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    vector<string> x;

    for (ll i = 0; i <= sn-tn; i++){
        bool p = true;
        string c = s;
        for (ll j = 0; j < tn; j++){
            if (s[i+j] != t[j] && s[i+j] != '?'){
                p = false;
                break;
            }
            else{
                c[i+j] = t[j];
            }
        }

        if (p){
            x.push_back(c);
        }
    }

    /*for (auto a : x){
        cout << a << endl;
    }*/

    if (x.size() == 0){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for (auto &a : x){
        rep(i,sn){
            if (a[i] == '?'){
                a[i] = 'a';
            }
        }
    }

    sort(x.begin(), x.end());

    cout << x[0] << endl;

}