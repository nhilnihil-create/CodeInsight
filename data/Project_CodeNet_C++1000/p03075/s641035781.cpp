#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i< (n); ++i)
#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int abs(int n, int m){
    if(n-m<0) return -(n-m);
    else return n-m;
}

int main(){
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;
    bool res = true;
    if(abs(a,b) > k) res = false;
    if(abs(a,c) > k) res = false;
    if(abs(a,d) > k) res = false;
    if(abs(a,e) > k) res = false;
    if(abs(b,c) > k) res = false;
    if(abs(b,d) > k) res = false;
    if(abs(b,e) > k) res = false;
    if(abs(c,d) > k) res = false;
    if(abs(c,e) > k) res = false;
    if(abs(d,e) > k) res = false;

    if(res) cout << "Yay!" << endl;
    else cout << ":(" << endl;
}