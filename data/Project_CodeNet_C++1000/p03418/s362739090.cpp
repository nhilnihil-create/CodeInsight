#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N,K;
    cin >> N >> K;
    ll sum = 0;
    for(ll b=1;b<=N;b++){
        ll q = N/b;
        ll r = N%b;
        sum += max(ll(0),b-K)*q;
        if(K == 0)sum--;
        sum += max(ll(0),r-K+1);
        //sum -= 1;
    }
    cout << sum << endl;
    
    /*
    for(ll i=K;i<=N;i++){
        sum += N-i;
    }
    for(ll i=2*K+1; i<=N;i++){
        sum += i/(K+1);
    }

    cout << sum << endl;
    */
}