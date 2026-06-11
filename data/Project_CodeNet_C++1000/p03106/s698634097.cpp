#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int a, b, k; cin >> a >> b >> k;
    int ans;

    for(int i = max(a, b); k > 0; i--){
        if(!(a % i) && !(b % i)){
            ans = i;
            k--;
        }
    }

    cout << ans << endl;
    return 0;
}