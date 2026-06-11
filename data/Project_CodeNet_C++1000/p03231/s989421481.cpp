#include <bits/stdc++.h>
using namespace std;

long long mygcd(long long a,long long b){
    return b ? mygcd(b,a % b) : a;
}

long long mylcm(long long a, long long b){
    return a * b / mygcd(a,b);
}

int main(){
    int n,m;
    string s,t;
    cin >> n >> m >> s >> t;
    long long ans = mylcm(n,m);
    int x,y;
    x = n / mygcd(n,m);
    y = m / mygcd(n,m);
    
    for(int i = 0; i < mygcd(n,m); i++){
        if(s[i*x] != t[i*y]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}

