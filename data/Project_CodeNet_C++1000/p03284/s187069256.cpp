#include <iostream>
using namespace std;
int main(){
    int n , k , mod;
    cin >> n >> k; mod = n % k;
    if (mod == 0) cout << 0;
    else cout << 1;
    return 0;
}