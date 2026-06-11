#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    int n;
    cin >> n;
    vector<int> x(n),y(n);
    rep(i,n){
        cin >> x[i];
        y[i] = x[i];
    }
    sort(y.begin(),y.end());
    int a = n/2;
    vector<int> b(2);
    b[0] = y[a-1],b[1] = y[a];
    rep(i,n){
        if(x[i] <= b[0]) cout << b[1] << endl;
        else cout << b[0] << endl;
    }
}