#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}



signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    int N = in();
    vector<int> a(N);
    REP(i,N)a[i] = in();
    int count = 0;
    int before = 0;
    REP(i,N){
        if(before == a[i]){
            count++;
            before = 0;
        }else{
            before = a[i];
        }
    }
    cout << count << "\n";
}