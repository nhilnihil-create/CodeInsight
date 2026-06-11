#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    int bin = (1<<k)-1;
    cout << a + b + c + max(a,max(b,c))*bin << endl;
}