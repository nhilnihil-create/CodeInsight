#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int d, n, ans = 0;
    cin >> d >> n;
    if(n != 100){
        if(d == 0) ans = n;
        else if(d == 1) ans = n * 100;
        else if(d == 2) ans = n * 10000;
    }
    else{
        if(d == 0) ans = 101;
        else if(d == 1) ans = 101 * 100;
        else if(d == 2) ans = 101 * 10000;
    }
    cout << ans << endl;
    return 0;
}