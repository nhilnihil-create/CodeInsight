#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
    ll N,K,c1=0,c2=0;
    cin >> N >> K;

    rep(i,N) {
        if((i+1)%K == 0)
            c1++;
        if(K%2==0 && (i+1)%K == K/2)
            c2++;
    }

    cout << setprecision(20) << pow(c1, 3) + pow(c2, 3) << endl;
}