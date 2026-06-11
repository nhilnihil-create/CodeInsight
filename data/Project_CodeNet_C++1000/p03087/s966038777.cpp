#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main(){
    int n,q; cin >> n >> q;
    vector<int> x(n);
    string s; cin >> s;
    vector<vector<int>> v(q,vector<int>(2));
    rep(i,q){
        cin >> v[i][0] >> v[i][1];
    }
    rep(i,n-1){
        if(s[i]=='A' && s[i+1]=='C') x[i+1]=1;
        else x[i+1]=0;
    }
    vector<int> a(n+1,0);
    a[0]=0;
    rep2(i,n+1){
        a[i]=a[i-1]+(int)x[i-1];
    }
    rep(i,q){
        cout << a[v[i][1]]-a[v[i][0]] << endl;
    }
    // rep(i,n+1){
    //     cout << i << " " <<  a[i] << endl;
    // }
}