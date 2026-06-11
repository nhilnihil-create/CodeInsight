#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PI 3.1415926535897932384626433
#define mod 1000000007

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(){
    int n[4];
    for (int i = 0; i < 4; i++){
        cin >> n[i];
    }
    sort(n, n + 4);
    if(n[0] == 1 && n[1] == 4 && n[2] == 7 && n[3] == 9){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}