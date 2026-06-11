#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    int A[N];
    rep(i, N) cin >> A[i];
    int l = 1, r = N;
    while(l < r){
        int n = (l+r)/2;
        bool able = true;
        map<int, int> mp;
        rep2(i, 1, N-1){
            if(A[i] > A[i-1]) continue;
            else{
                if(n == 1){able = false; break;}
                mp[A[i]] = 0;
                map<int, int>::iterator ite;;
                ite = mp.find(A[i]);
                while(ite != mp.end()) ite = mp.erase(ite);
                if(mp.count(A[i]-1)) mp[A[i]-1]++;
                else mp[A[i]-1] = 1;
                int j = A[i]-1;
                while(mp[j] >= n){
                    if(j == 0){able = false; break;}
                    mp.erase(j);
                    j--;
                    if(mp.count(j)) mp[j]++;
                    else mp[j] = 1;
                }
            }
        }
        if(able) r = n;
        else l = n+1;
    }
    cout << l << endl;
}