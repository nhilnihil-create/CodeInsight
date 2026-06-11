#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    ll N,A,B,C,D,E;
    cin >> N >> A >> B >> C >> D >> E;
    ll min_dist;
    min_dist = min(A,min(B,min(C,min(D,E))));
    //cout << min_dist << endl;
    
    cout << 5 + (N-1)/min_dist << endl;
}
