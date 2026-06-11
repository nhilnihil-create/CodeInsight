#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    ll cnt = 0;
    rep(i,n) {
        int a;
        cin >> a;
        while(a%2==0){
            a/=2;   
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}