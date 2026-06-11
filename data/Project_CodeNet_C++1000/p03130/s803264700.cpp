#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mod 1000000007
 
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
 
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(){
    vector<int> w(10, 0);
    for (int i = 0; i < 6; i++){
        int a;
        cin >> a;
        w[a]++;
    }
    if(w[1] > 2 || w[2] > 2 || w[3] > 2 || w[4] > 2){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}