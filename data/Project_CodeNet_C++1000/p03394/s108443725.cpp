#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll N;
    cin >> N;
    int n=N/8,m=N%8;
    vector<int> v={2,3,4,6,8,9,10,12};
    rep(i,n){
        rep(j,8){
            cout << v[j]+12*i << ' ';
        }
    }
    rep(i,8){
        v[i]+=12*n;
    }
    if (m==1){
        cout << v[7] << endl;
    }
    else if (m==2){
        cout << v[0] << ' ' << v[2] << endl;
    }
    else if (m==3){
        if (N==3){
            cout << 2 << ' ' << 5 << ' ' << 63 << endl;
        }
        else {
            cout << v[0] << ' ' << v[2] << ' ' << v[3] << endl;
        }
    }
    else if (m==4){
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[5] << endl;
    }
    else if (m==5){
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[5] << ' ' << v[7] << endl;
    }
    else if (m==6){
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[4] << ' ' << v[5] << ' ' << v[6] << endl;
    }
    else if (m==7){
        rep(i,m){
            cout << v[i];
            if (i!=m-1){
                cout << ' ';
            }
            else {
                cout << endl;
            }
        }
    }
    else {
        cout << endl;
    }
}