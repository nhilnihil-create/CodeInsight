#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(long long N, long long Y){
    bool check = true;
    ll A = -1; ll B = -1; ll C = -1;
    for(ll x = 0; x <= N; ++x){
        for(ll y = 0; y <= N; ++y){
            if(9000 * x + 4000 * y == Y - 1000 * N && N - x - y >= 0){
                A = x;
                B = y;
                C = N - x - y;
            }
        }
    }
    cout << A << " " << B << " " << C << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long Y;
    scanf("%lld",&Y);
    solve(N, Y);
    return 0;
}