#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mod 1000000007
 
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
 
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(){
    string s;
    cin >> s;
    int batu_cnt = 0;
    for (int i = 0; i < s.size(); i++){
        if(s[i] == 'x'){
            batu_cnt++;
        }
    }
    if(batu_cnt >= 8){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}