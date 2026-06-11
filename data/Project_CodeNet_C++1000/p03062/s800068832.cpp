#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    int cnt = 0;
    ll num = INF;
    ll sum = 0;
    rep(i,N){
        cin >> A[i];
        if(A[i]<0) cnt++;
        num = min(num,abs(A[i]));
        sum += abs(A[i]);
    }
    if(cnt%2==0){
        cout << sum << endl;
    }else{
        cout << sum-num*2 << endl;
    }
    return 0;
}