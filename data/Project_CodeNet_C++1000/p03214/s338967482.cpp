#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mod 1000000007
 
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
 
int lcm(int a, int b) { return a * b / gcd(a, b); }
 
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
 
    double ave = 0;
    for(int i = 0; i < n; i++){
        ave += a[i];
    }
    ave /= n;
 
    ll ans_min = 0;
    for(int i = 1; i < n; i++){
        if(abs(a[i] - ave) < abs(a[ans_min] - ave)){
            ans_min = i;
        }
    }
    cout << ans_min << endl;
    return 0;
}