#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void){
    double x;
    cin >> x;
    int ans = -1;
    if(x == 1){
          ans = 1;
    }else{
          for(int i = 2;i * i <= x;i++){
                int temp = i * i;
                while(temp <= x){
                      temp *= i;
                }
                temp /= i;
                ans = max(ans,temp);
          }
    }
    cout << ans << endl;
}
