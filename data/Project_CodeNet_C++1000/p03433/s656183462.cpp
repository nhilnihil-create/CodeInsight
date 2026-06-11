#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,a; 
    cin >> n >> a;
    n %= 500;
    if(n <= a) puts("Yes");
    else puts("No");
    return 0;
}
