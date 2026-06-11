#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    int lim=1e5+5;
    vector<bool> chk(lim,false);
    for(int i = 3; i < lim; i++) {
        if(i%2==0) continue;
        int n=i;
        int m=(i+1)/2;
        bool flag=true;
        int d=2;
        while(d*d<=n) {
            if(n%d==0) flag=false;
            d++;
        }
        d=2;
        while(d*d<=m) {
            if(m%d==0) flag=false;
            d++;
        }
        if(flag) chk[i]=true;
    }

//    for(int i = 0; i < 10; i++) {
//        cout << i << " " << chk[i] << "\n";
//    }

    vector<int> cnt(lim,0);
    for(int i = 0; i < lim; i++) {
        cnt[i]=cnt[i-1]+chk[i];
    }

    for(int i = 0; i < q; i++) {
        int l,r;
        cin >> l >> r;
        l--;
        cout << cnt[r]-cnt[l] << "\n";
    }

    return 0;
}