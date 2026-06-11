#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
using ping = pair<ll, ll>;

int main(){
    ll N, K;
    cin >> N >> K;
    ll A[100100]={0};
    for(int i = 0; i < N; i++)cin >> A[i];
    ll cnt = 0;
    if ((N - 1) % (K - 1) == 0) {
      cnt = (N - 1) / (K - 1);
    }
    else{
        cnt = (N - 1) / (K - 1)+1;
    }
    cout << cnt << endl;
    return 0;
}