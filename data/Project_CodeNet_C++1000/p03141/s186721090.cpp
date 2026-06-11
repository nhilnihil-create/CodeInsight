#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N),B(N);
    ll sumA =0;
    vector<ll> point(N);
    for(int i=0;i<N;i++){
        cin >> A[i] >> B[i];
        sumA += B[i];
        point[i] = A[i] + B[i];
    }
    ll ans  = -sumA;
    sort(point.rbegin(),point.rend());
    for(int i=0;i<N;i++){
        if(i%2==1){
            continue;
        }
        ans += point[i];
    }
    cout << ans << endl;


    return 0;
}