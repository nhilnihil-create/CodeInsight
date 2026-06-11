#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

vector<int> sieve(int n){
    vector<bool> is_prime(n+1, true);
    vector<int> p;
    for(int i=2; i<=n; i++){
        if(is_prime[i]) {
            for(int j=2*i; j<=n; j+=i){
                is_prime[j] = false;
            }
            p.emplace_back(i);
        }
    }
    return p;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<int> p = sieve(55555);
    int cnt = 0;
    for(auto a : p){
        if(a % 5 == 1){
            cout<<a<<" ";
            cnt++;
        }
        if(cnt == n) break;
    }
    cout<<endl;
    return 0;
}
// abc096_d