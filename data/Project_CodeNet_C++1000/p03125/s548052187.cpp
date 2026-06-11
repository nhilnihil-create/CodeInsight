#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main(void){
    int a, b;
    cin >> a >> b;
    int ans;
    if(b % a == 0){
        ans = a + b;
    }else{
        ans = b - a;
    }
    cout << ans;
}