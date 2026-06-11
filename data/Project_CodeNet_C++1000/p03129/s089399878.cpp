#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PI 3.1415926535897932384626433
#define mod 1000000007

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(){
    int n, k;
    cin >> n >> k;
    if(k*2-1 <= n){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
