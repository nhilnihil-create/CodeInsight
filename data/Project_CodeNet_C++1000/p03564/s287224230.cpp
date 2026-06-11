#include <iostream>
using namespace std;
int main(){
    int d=1, n, k;
    cin >> n >> k;
    while(n!=0){
        d = min(d*2,d+k);
        n--;
    }
    cout << d << endl;
    return 0;
}