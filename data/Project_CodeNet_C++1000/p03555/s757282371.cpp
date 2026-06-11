#include <iostream>
#include <string>
using namespace std;
int main(){
    string u,l;
    cin >> u >> l;
    if(u[0] == l[2] && u[2] == l[0] && u[1] == l[1]) puts("YES");
    else puts("NO");
    return 0;
}