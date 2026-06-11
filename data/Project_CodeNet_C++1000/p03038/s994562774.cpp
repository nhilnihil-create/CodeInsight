// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<ll, int> P;
const int INF = 1000000007;

int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<P> B(M);
    
    rep(i, N) cin >> A[i];
    sort(all(A));

    rep(i, M){
        P tmp;
        cin >> tmp.second >> tmp.first;
        B[i] = tmp;
    }

    sort(all(B));
    reverse(all(B));

    vector<ll> rewrite(N, 0);
    int index = 0;
    for(auto i : B){
        for(int j = 0; j < i.second && index < N; j++){
            rewrite[index] = i.first;
            index++;
        }
        if(index == N) break;
    }

    ll sum = 0;
    rep(i, N){
        if(rewrite[i] > A[i]) sum += rewrite[i];
        else sum += A[i];
    }

    cout << sum << endl;

}