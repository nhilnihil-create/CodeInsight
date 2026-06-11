#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod=1e9+7;

int main(){
    ll N, H, W;
    cin >> N >> H >> W;
    int cnt=0;
    for(int i=0; i<N; i++){
        ll A, B;
        cin >> A >> B;
        if(A>=H && B>=W) cnt++;
    }
    cout << cnt;
}