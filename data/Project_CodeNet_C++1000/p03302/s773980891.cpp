#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PI 3.1415926535897932384626433
#define mod 1000000007

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(){
    int a, b;
    cin >> a >> b;
    if(a + b == 15){
        cout << '+' << endl;
    }else if(a * b == 15){
        cout << '*' << endl;
    }else{
        cout << "x" << endl;
    }
    return 0;
}
