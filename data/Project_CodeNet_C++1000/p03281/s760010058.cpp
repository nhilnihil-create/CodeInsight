#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int divcount(int n)
{
    int ret = 0;
    for(int i = 1; i*i <= n; i++){
        if(!(n % i)){
            ret++;
            if(n != i*i) ret++;
        }
    }

    return ret;
}

int main()
{
    int n; cin >> n;
    int ans = 0;

    for(int i = 1; i <= n; i += 2){
        if(divcount(i) == 8) ans++;
    }

    cout << ans << endl;
    return 0;
}
