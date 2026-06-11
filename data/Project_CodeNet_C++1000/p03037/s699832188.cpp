#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> l(m),r(m);
    int lmax=1, rmin=100000;
    for(int i=0; i<m; i++){
        cin >> l.at(i) >> r.at(i);
        lmax=max(l.at(i),lmax);
        rmin=min(r.at(i),rmin);
    }
    if(rmin-lmax+1>0) cout << rmin-lmax+1 << endl;
    else cout << 0 << endl;
}