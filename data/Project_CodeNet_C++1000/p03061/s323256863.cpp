#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;



int main(){
    int N; cin >> N;
    vi A(N);
    for(auto &x: A) cin >> x;

    vi L(N+1, 0), R(N+1, 0);
    for(int i=0; i<N; i++){
        L[i+1]=__gcd(L[i], A[i]);
        R[N-i-1]=__gcd(R[N-i], A[N-i-1]);
    }
    int ans=0;
    for(int i=0; i<N; i++){
        ans=max(ans, __gcd(L[i], R[i+1]));
    }
    cout << ans << endl;
    return 0;
}