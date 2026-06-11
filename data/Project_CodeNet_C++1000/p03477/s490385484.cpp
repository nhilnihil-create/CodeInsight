#include <iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a+b == c+d) puts("Balanced");
    else if(a+b < c+d) puts("Right");
    else puts("Left");
    return 0;
}