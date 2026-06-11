#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

vec<int> C = {2,5,5,4,5,6,3,7,6};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vec<int> A(M);
    for(int i=0;i<M;i++){
        cin >> A[i];
        A[i]--;;
    }
    sort(A.begin(),A.end());
    vec<int> dp(N+1,-1e9);
    dp[0] = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) if(i+C[A[j]]<=N){
            dp[i+C[A[j]]] = max(dp[i+C[A[j]]],dp[i]+1);
        }
    }
    string ans = "";
    int now = N;
    while(now){
        for(int j=M-1;j>=0;j--) if(now-C[A[j]]>=0 && dp[now]==dp[now-C[A[j]]]+1){
            char c = '0'+(A[j]+1);
            ans += c;
            now -= C[A[j]];
            break;
        }
    }
    cout << ans << "\n";
}