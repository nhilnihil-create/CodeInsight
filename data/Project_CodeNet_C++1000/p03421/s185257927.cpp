#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
using P3 = pair<P, int>;
using ll = long long int;
constexpr int INF = 1<<30;
constexpr ll MOD = (1e9)+7;

int main(){
    ll N, A, B;
    cin >> N >> A >> B;
    if(A+B > N+1 || A*B < N){
        cout << -1 << endl;
        return 0;
    }
    vector<ll> ans(N), num(N);
    vector<bool> used(N);
    int idx = 0;
    for(int i=0;i<A;i++){
        for(int j=0;j<B&&(idx+(A-1-i)<N);j++){
            num[idx++] = (B-1-j)*A+i;
        }
    }
    ans = num;
    map<ll,ll> mp;
    sort(num.begin(), num.end());
    for(int i=0;i<N;i++){
        mp[num[i]] = i+1;
    }
    for(int i=0;i<N;i++){
        cout << mp[ans[i]] << " \n"[i==N-1];
    }

    return 0;
}
