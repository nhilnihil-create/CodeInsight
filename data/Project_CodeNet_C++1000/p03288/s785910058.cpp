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
    int r;
    cin >> r;
    string ans = "AGC";
    if(r < 1200) ans = "ABC";
    else if(r < 2800) ans = "ARC";
    cout << ans << endl;
    return 0;
}