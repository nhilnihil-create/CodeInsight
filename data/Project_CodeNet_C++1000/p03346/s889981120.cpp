#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    vector<int> cnt(n,0);
    rep(i,n){
        int c; cin >> c;
        c--;
        if(c != 0) cnt[c] = cnt[c-1]+1;
        else cnt[c]++;
    }
    int nmax = 0;
    rep(i,n) nmax = max(nmax,cnt[i]);
    cout << n-nmax << endl;
}