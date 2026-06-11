#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a <= c && c <= b || b <= c && c <= a) puts("Yes");
    else puts("No");
    return 0;
}