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
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
        int div = 536870912; //div = 2**29
        for(int j = 29; j >= 1; --j){
            if(a.at(i) % div == 0){
                ans += j;
                break;
            }
            else div /= 2; 
        }
    }
    cout << ans << endl;
    return 0;
}