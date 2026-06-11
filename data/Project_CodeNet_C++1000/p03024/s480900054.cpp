#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
#define mod 1000000007

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;} 
ll lcm(ll x,ll y) {return x/gcd(x,y)*y;}

int main(){
    string s;
    cin >> s;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='x') cnt++;
    }
    if(cnt>7) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}









