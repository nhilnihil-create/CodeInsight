#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 200000000000
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
    ll N,ans = 0;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        cin >> B[i];
    }
    rep(i,N){
        cin >> C[i];
    }
    sort(all(A));
    sort(all(B));
    sort(all(C));
    vector<ll> AB(N);
    AB[0] = lower_bound(all(A), B[0]) - A.begin();
    rep3(i,1,N){
        AB[i] = AB[i-1] + lower_bound(all(A), B[i]) - A.begin();
        
    }
    rep(i,N){
        ll b = lower_bound(all(B), C[i]) - B.begin();
        if(b!=0)
            ans += AB[b-1];
    }
    cout << ans <<endl;


    return 0;
    

}