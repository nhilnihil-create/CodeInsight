#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int main(){
    int N, M, A, B, C;
    string s1, s2;
    cin >> N;
    vector<ll> a(N), x(N);
    rep(i, N) cin >> a[i];
    x = a;
    sort(all(a));
    int i1 = N / 2 - 1;
    int i2 = N / 2;
    rep(i, N){
        if(x[i] <= a[i1]){
            cout << a[i2] << endl;
        }else{
            cout << a[i1] << endl;
        }
    }
    

  }