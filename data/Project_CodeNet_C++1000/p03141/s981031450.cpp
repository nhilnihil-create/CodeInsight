#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<ll> A(N),B(N);
    priority_queue<pair<ll,int>> pq;
    rep(i,N){
        cin >> A[i] >> B[i];
        pq.push(make_pair(A[i]+B[i],i));
    }
    ll Taka=0;
    ll Aoki=0;
    ll i=0;
    while(!pq.empty()){
        auto P = pq.top();
        pq.pop();
        if(i%2==0){
            Taka += A[P.second];
        }else{
            Aoki += B[P.second];
        }
        i++;
    }
    cout << Taka - Aoki << endl;
    return 0;
}