#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
int main(){
    int n; 
    cin >> n;
    if(n < 1200) out("ABC");
    else if(n < 2800) out("ARC");
    else out("AGC");
}