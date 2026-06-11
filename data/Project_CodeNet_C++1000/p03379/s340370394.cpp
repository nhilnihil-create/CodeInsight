#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int>x(n);
    rep(i,n)cin >> x[i];
    vector<int>y(n);
    rep(i,n)y[i] = x[i];
    sort(all(y));
    int m = y[n/2-1];
    rep(i,n){
        if(x[i]>m)cout << m << endl;
        else cout << y[n/2] << endl;
    }
    return 0;
}