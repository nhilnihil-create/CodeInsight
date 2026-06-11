#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b;
    c = b-a;
    int x = (c-1)*c/2;
    cout << x-a<<endl;
}
int main(){
   solve();
}
