#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF= 1LL << 60;
#define REP(i,n) for(ll i=0; i<n; i++)
#define FOR(i,a,n) for(ll i=a; i<n; i++)

struct c{
    int num,sum;
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);    
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    vector<c> C(n);
    REP(i,n){
        cin >> A[i] >> B[i];
        C[i].num= i;
        C[i].sum= A[i]+B[i];
    }
    sort(C.begin(), C.end(), [](const c &a, const c &b) { return a.sum > b.sum; });

    ll s= 0;
    REP(i,n){
        // cout << C[i].num << " " << C[i].sum << endl;
        s+= (i&1)?-B[C[i].num]:A[C[i].num];
        // cout << s << endl;
    }
    cout << s << endl;
}   