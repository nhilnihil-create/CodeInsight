#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n;
    cin >> n;

    ll s = 0;
    ll e = n;
    ll m = 0;
    bool f[n];
    string tmp;

    rep(i, 0, 20){
        if(i == 0){
            cout << 0 << endl;
            cin >> tmp;
            if(tmp == "Male"){
                rep(i, 0, n){
                    if(i % 2 == 0){
                        f[i] = true;
                    }else{
                        f[i] = false;
                    }
                }
            }else if(tmp == "Female"){
                rep(i, 0, n){
                    if(i % 2 == 0){
                        f[i] = false;
                    }else{
                        f[i] = true;
                    }
                }
            }else{
                return 0;
            }
        }else{
            m = (s + e) / 2;
            cout << m << endl;
            cin >> tmp;
            if(tmp == "Male"){
                if(f[m] == true){
                    s = m;
                }else{
                    e = m;
                }
            }else if(tmp == "Female"){
                if(f[m] == true){
                    e = m;
                }else{
                    s = m;
                }
            }else{
                return 0;
            }
        }
    }
}
