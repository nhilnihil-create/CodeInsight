#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define sort(s) sort(s.begin(),s.end())
#define reverse(s) reverse(s.begin(),s.end())

//最大公約数
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}
//最小公倍数
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(){
    int a,b;
    cin >> a >> b;
    if(a*b%2==0)    puts("Even");
    else
    {
        puts("Odd");
    }
    
    return 0;
}