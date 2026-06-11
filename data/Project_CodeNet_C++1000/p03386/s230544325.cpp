#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    ll a,b;
    cin >> a >> b;
    int k;
    cin >> k;
    for(int i=a;i<b+1;i++){
        if(i<a+k)cout << i << endl;
        else if(i>b-k) cout << i << endl;
    }
}
