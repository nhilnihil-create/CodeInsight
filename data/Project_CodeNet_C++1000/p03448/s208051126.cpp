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
    int a, b, c, x, ans = 0;
    cin >> a >> b >> c >> x;
    for(int i = 0; i < a + 1; ++i){
        for(int j = 0; j < b + 1; ++j){
            for(int k = 0; k < c + 1; ++k){
                if(i * 500 + j * 100 + k * 50 == x) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}