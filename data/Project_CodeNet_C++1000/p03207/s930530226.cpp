#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    int n; cin >> n;
    int max_num = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int p; cin >> p;
        ans += p;
        max_num = max(max_num, p);
    }
    cout << ans - max_num/2 << endl;
    return 0;
}