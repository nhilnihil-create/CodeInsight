#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pil = pair<pii,int>;

int a(int c){
    int s = pow(c+1,2);
    return s;
}

int main(){
    int n;
    cin >> n;
    int ans;
    rep(i,n){
        int b = a(i);
        if(n >= b) ans = b;
        else break; 
    }
    cout << ans << endl;
}