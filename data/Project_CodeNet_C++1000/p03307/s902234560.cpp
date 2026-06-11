#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll fact(int i) {       //階乗
    if (i == 0) return 1;
    return (fact(i - 1)) * i;
}
ll gcm(ll a, ll b) {        //最大公約数
    if(b == 0) return a;
    return gcm(b, a % b); 
}
ll lcm(ll a, ll b) {
    return a * b / gcm(a, b);
}
int d(ll n) {
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << lcm(2, n) << endl;
}