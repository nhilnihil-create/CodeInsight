#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(void){
    vector<int>a(3);
    int s = 0;
    for(int i = 0;i < 3;i++){
          cin >> a[i];
          s += a[i];
    }
    sort(a.begin(),a.end());
    int t = a[2] * 3;
    int ans = (t - s) / 2 + (t - s) % 2 * 2;
    cout << ans << endl;
}
