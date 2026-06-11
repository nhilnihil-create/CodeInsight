#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> x(n),y(n);
    rep(i,n){
        int t;
        cin >> t;
        x[i] = t;
        y[i] = t;
    }
    sort(y.begin(),y.end());
    int midl = y[n/2-1];
    int midr = y[n/2];
    rep(i,n){
        if(x[i]<=midl) cout << midr << endl;
        else if(x[i]>=midr) cout << midl << endl;
    }
    return 0;
}