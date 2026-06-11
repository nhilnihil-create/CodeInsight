#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9
 
bool isacgt(char c){
    return (
        c=='A' || c=='C' || c=='G' || c=='T'
    );
}

int main() {

    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    
    int lcost=0, rcost=0, ans=0;
    rep(i,m){
        if(a[i]<x) lcost++;
        else rcost++;
    }
    ans = min(lcost,rcost);

    cout << ans << endl;

    return 0;

}