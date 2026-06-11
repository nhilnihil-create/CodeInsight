#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    int N;
    cin>>N;
    int sum = 0;
    int max = 0;
    rep(i, N){
        int p;
        cin>>p;
        sum += p;
        max = std::max(max, p);
    }

    cout << (sum-max+max/2) << endl;
}
