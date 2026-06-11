#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    if(k*2-1 <= n) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}