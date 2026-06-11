#include <iostream>
using namespace std;
int main(){
    int a,b,k;
    cin >> a >> b >> k;
    int nnum = min(b, a+k-1);
    int xnum = max(a, b-k+1);
    for(int i = a; i < b+1; i++){
        if(i <= nnum || xnum <= i) cout << i << endl;
        else continue;
    }
    return 0;
}



