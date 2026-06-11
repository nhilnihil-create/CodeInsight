#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    vector<pair<ll,ll>> C(N),D(N);
    rep(i,N){
        cin >> A[i] >> B[i];
        C[i] = make_pair(A[i] + B[i], i);
        //D[i] = make_pair(B[i] - A[i], i);
    }
    sort(C.begin(), C.end(), greater<pair<ll,ll>>());
    //sort(D.begin(), D.end(), greater<pair<ll,ll>>());
    ll L = 0;
    ll R = N-1;
    ll tak = 0;
    ll aok = 0;
    rep(i,N){
        if(i % 2 == 0){
            tak += A[C[i].second];
        }else if(i % 2 == 1){
            aok += B[C[i].second];
        }
    }
    cout << tak - aok << endl;
}