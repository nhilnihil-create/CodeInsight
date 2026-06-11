#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int m = max(a,max(b,c));
    cout << m * 10 + (a + b + c - m) << endl;
}
