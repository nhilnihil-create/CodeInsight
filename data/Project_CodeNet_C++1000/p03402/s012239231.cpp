#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

int main(){
    int A,B;
    cin >> A >> B;
    A--,B--;
    int a1=A/50,a2=A%50,b1=B/50,b2=B%50;
    int h=((A+49)/50+(B+49)/50+1)*2;
    cout << h << ' ' << 100 << endl;
    rep(i,a1){
        rep(j,100){
            cout << '#';
        }
        cout << endl;
        rep(j,50){
            cout << "#.";
        }
        cout << endl;
    }
    if (a2>0){
        rep(j,100){
            cout << '#';
        }
        cout << endl;
        rep(j,a2){
            cout << "#.";
        }
        rep(j,100-2*a2){
            cout << '#';
        }
        cout << endl;
    }
    rep(j,100){
        cout << '#';
    }
    cout << endl;
    rep(i,b1){
        rep(j,100){
            cout << '.';
        }
        cout << endl;
        rep(j,50){
            cout << ".#";
        }
        cout << endl;
    }
    if (b2>0){
        rep(j,100){
            cout << '.';
        }
        cout << endl;
        rep(j,b2){
            cout << ".#";
        }
        rep(j,100-2*b2){
            cout << '.';
        }
        cout << endl;
    }
    rep(j,100){
        cout << '.';
    }
    cout << endl;
}