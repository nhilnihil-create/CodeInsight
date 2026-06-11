#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int D; cin >> D;
    if(D == 22) puts("Christmas Eve Eve Eve");
    else if (D == 23) puts("Christmas Eve Eve");
    else if (D == 24) puts("Christmas Eve");
    else puts("Christmas");
    return 0;
}