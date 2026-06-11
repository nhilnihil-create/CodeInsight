#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector <int> l(n);
    int wa=0,ma=0;
    rep(i,n){
        cin >> l[i];
        ma=max(ma,l[i]);
        wa+=l[i];
    }

    if(2*ma<wa){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    

    return 0;
}