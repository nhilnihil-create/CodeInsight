#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

ll gcd(ll x, ll y) {
    if (x % y == 0) {
        return y;
    }

    else {
        return gcd(y, x % y);
    }
}

int main() {
    int T;
    cin>>T;
    for(int i = 0; i < T; i++){
        ll A,B,C,D;
        cin>>A>>B>>C>>D;
        bool can;
        if(D<B) can = false;
      	else if(A<B) can = false;
        else if(A%B>C) can = false;
        else if(C>=B) can = true;
        else {
            ll E = A%B;
            ll F = gcd(B,D);
            if((B-E-1)/F!=(C-E)/F) can = false;
            else can = true;
        }
        if(can) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}