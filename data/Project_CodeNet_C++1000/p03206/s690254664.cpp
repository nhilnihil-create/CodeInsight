#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    int D; cin>>D;
    if(D == 25){
        cout << "Christmas" << endl;
    }
    if(D == 24){
        cout << "Christmas Eve" << endl;
    }
    if(D == 23){
        cout << "Christmas Eve Eve" << endl;
    }
    if(D == 22){
        cout << "Christmas Eve Eve Eve" << endl;
    }
}
