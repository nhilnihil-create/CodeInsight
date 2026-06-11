#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    int l,r;
    l=0;
    r=100000;
    for(int i=0; i<m; i++){
        int p,q;
        cin >> p >> q;
        l = max(l, p);
        r = min(r,q);
    }
    cout << max(0,r-l+1) << endl;
}