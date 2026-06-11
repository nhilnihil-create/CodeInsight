#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define _GLIBCXX_DEBUG
#define rep(i, V) for (int i = 0; i < V; i++)
#define repr(i, V) for (int i = V-1; i >= 0; i--)
#define repval(i, a, V) for (int i = a; i < V ; i++)
#define all(x) x.begin(), x.end()
#define ld long double
#define eps 0.0000000001
#define mod 1000000007
#define inf 1e9
#define vec vector
#define each(i, mp) for(auto& i:mp)

int nmax = 100001;

int main(){
    vec<bool> f(nmax, false); //素数がfalse
    vec<int> c(nmax,0);
    repval(i, 2, nmax) if(!f[i]) for(int j=i+i; j<nmax; j+=i){
        f[j] = true;
    }
    for(int i=3; i<nmax; i+=2){
        if(!f[i] && !f[(i+1)/2]) c[i]++;
    }
    repval(i, 3, nmax) c[i] += c[i-1];
    int q;
    cin >> q;
    int l, r;
    rep(i, q){
        cin >> l >> r;
        cout << c[r]- c[l-1] << endl;
    }
}