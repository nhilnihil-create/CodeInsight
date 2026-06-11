#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    int N;
    cin>>N;
    int h[N];
    rep(i, N) cin>>h[i];

    int max = h[0];
    int min = h[0];
    int count = 0;
    FOR(i, 1, N){
        max = std::max(max, h[i]);
        min = std::min(min, h[i]);

        if(h[i-1] == h[i]) h[i-1] = max; 

        if(i < N-1 && h[i-1] > h[i] && h[i] < h[i+1]){
            count += max - h[i];
            max = h[i];
            min = h[i];
        }

        if(i == N-1){
            count += max;
        }
    }

    if(N == 1) count = h[0];

    cout << count << endl;
}
