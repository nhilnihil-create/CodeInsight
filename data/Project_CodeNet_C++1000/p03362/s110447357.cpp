#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
//#define MOD 1000000007
const int INF = 1LL<<30;

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin>>n;

    vector<int> ans;
    for(int i=2;i<55555;i++){
        if(is_prime(i) && i%5==1) ans.push_back(i);
    }
    //cout<<ans.size()<<endl;

    rep(i,n) cout<<ans[i]<<" ";
    cout<<endl;
}