#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mod 1000000007
 
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
 
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(){
    string s;
    int w;
    cin >> s >> w;
    int len = s.size();
    for (int i = 0; i < len; i++){
        if((i - w) % w == 0){
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}