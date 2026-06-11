#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    ll H;
    cin >> H;
    vector<ll> A(N);
    vector<ll> B(N);
    rep(i,N){
        cin >> A[i];
        cin >> B[i];
    }
    sort(all(A));
    sort(all(B));
    ll max_swing = A[N - 1];
    ll count = 0;
    rep(i,N){
        if (H <= 0 || B[N - i - 1] <= max_swing){
            break;
        }
        else{
            count++;
            H -= B[N - 1 - i];
        }
    }
    if (H <= 0) count += 0;
    else if (H % max_swing == 0) count += H / max_swing;
    else count += (H / max_swing + 1);
    cout << count << endl;
}
