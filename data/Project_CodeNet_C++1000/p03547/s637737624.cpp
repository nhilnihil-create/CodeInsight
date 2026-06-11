#include <iostream>
using namespace std;
int main(){
    char a,b;
    cin >> a >> b;
    int x = (int)a;
    int y = (int)b;
    if(x < y) puts("<");
    else if(y < x) puts(">");
    else puts("=");
    return 0;
}