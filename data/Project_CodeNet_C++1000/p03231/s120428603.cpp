#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull gcd(ull a, ull b){
    if(a%b==0) return b;
    else return gcd(b, a%b);
}
ull lcm(ull a, ull b){
    return a * b / gcd(a, b);
}


int main(){
    ull n,m ; cin >> n >> m;
    string s,t ; cin >> s >> t;
    ull l = lcm(n, m);
    ull l_sub = lcm(l/n, l/m);
    bool flg = true;
    if(s.at(0) != t.at(0)){
        flg =false;
        cout << -1 << endl;
        return 0;
    }
    for(int i=0; i<l; i+=l_sub){
        if(s[i/(l/n)] != t[i/(l/m)]){
            cout << -1 << endl;
            return 0;
        }
    }
    if(flg) cout << l << endl;
    return 0;
}