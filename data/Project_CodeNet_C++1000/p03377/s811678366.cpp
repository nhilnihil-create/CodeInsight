#include <iostream>
using namespace std;
int main(){
    int a,b,x;
    cin >> a >> b >> x;
    if(x < a || a+b <= x) puts("NO");
    else puts("YES");
    return 0;
}