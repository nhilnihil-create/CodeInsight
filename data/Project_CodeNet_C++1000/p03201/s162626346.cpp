#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define rep3(i, n) for(int i = n-1; i >= 0; i--)
#define rep4(i, x, n) for(int i = x; i > n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    int N;
    cin >> N;
    ll A[N];
    rep(i, N) cin >> A[i];
    map<ll, int> mp;
    sort(A, A+N, greater<ll>());
    rep(i, N){
        if(mp.count(A[i])) mp[A[i]]++;
        else mp.insert(P(A[i], 1));
    }
    ll M = A[0];
    ll e[40];
    e[0] = 1;
    rep2(i, 1, 40) e[i] = e[i-1]*2;
    int n = 0;
    while(M >= e[n]){
        if(M >= e[n+1]) n++;
        else break;
    }
    int j = 0;
    int pos[n+2];
    pos[n+1] = -1;
    rep3(i, n+1){
        while(j+1 < N && A[j+1] >= e[i]) j++;
        pos[i] = j;
    }
    ll count = 0;
    rep3(i, n+1){
        rep2(j, pos[i+1]+1, pos[i]+1){
            if(mp[A[j]]){
                ll k = e[i+1]-A[j];
                if(mp.count(k) && mp[k]){
                    if(k == A[j]){
                        if(mp[A[j]] >= 2){
                            count++;
                            mp[A[j]] -= 2;
                        }
                    }
                    else{
                        count++;
                        mp[A[j]]--;
                        mp[k]--;
                    }
                }
            }
        }
    }
    cout << count << endl;
}