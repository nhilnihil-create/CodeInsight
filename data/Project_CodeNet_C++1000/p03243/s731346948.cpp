#include <iostream>
using namespace std;
int main(void){
    int n; cin >> n;
    int ans = n % 111 == 0 ? n : n + (111 - (n % 111));
    cout << ans << endl;
    return 0;
}