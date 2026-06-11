#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int m = max(max(a,b),c);
    int s = a*b*c/m;
    cout << s/2 << endl;
}