#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void){
    int n,t,a;
    cin >> n;
    cin >> t >> a;
    vector<int> h(n);
    int ans = -1;
    double diff = 10000;
    for(int i = 0;i < n;i++){
          cin >> h[i];
          double temp = abs(a - (t - h[i] * 0.006));
          if(temp < diff){
                diff = temp;
                ans = i + 1;
          }
    }
    cout << ans << endl;
}
