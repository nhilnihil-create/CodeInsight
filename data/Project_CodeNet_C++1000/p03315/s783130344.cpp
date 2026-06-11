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
    string s;
    cin >> s;
    int p = 0, m = 0, ans = 0;
    for(int i = 0; i < 4; ++i){
        if(s.at(i) == '+') p++;
        else m++;
    }
    ans = p - m;
    cout << ans << endl;
    return 0;
}