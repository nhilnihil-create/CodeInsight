#include<bits/stdc++.h>

using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int add=a+b;
    int sub=a-b;
    int mul=a*b;
    int ans = max(max(add,mul),sub);
    cout << ans << endl;
    return 0;
}