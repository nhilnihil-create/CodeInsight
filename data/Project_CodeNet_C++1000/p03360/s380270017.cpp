#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pil = pair<pii,int>;


int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int k;
    cin >> k;
    int m = max({a,b,c});
    int d =  m;
    rep(i,k) m *= 2;
    cout << a+b+c+m-d << endl; 
}