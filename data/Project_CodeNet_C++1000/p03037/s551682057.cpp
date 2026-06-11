#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n);i++)
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    int l_max=0, r_min=10000000;
    rep(i, m){
        cin >> l[i] >> r[i];
        if(l[i]>l_max) l_max = l[i];
        if(r[i]<r_min) r_min = r[i];
    } 
    int res=0;
    if(r_min >= l_max)
        res = r_min - l_max + 1;
    else
        res = 0;
    

    cout << res << endl;
}