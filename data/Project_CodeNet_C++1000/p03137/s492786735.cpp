#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> x(m);
    vector<int> kyori(m-1);
    ll zentai = 0;
    rep(i,m) cin >> x[i];
    
    if(n>=m){
        cout << 0 <<endl;
        return 0;
    }
    
    sort(x.begin(),x.end());

    rep(i,m-1){
        int l = abs(x[i]-x[i+1]);
        kyori[i] = l;
        zentai += l;
    }
    sort(kyori.rbegin(),kyori.rend());
    
    int jokyo = n-1;
    rep(i,jokyo){
        zentai -= kyori[i];
    }
    cout << zentai <<endl;
    return 0;
    
}