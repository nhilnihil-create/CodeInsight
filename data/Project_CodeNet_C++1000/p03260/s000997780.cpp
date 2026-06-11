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
    int a, b;
    string ans = "Yes";
    cin >> a >> b;
    if(a * b % 2 == 0) ans = "No";
    cout << ans << endl;
    return 0;
}