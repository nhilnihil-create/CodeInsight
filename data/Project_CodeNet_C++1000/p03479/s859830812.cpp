#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
using namespace std;

int main(){
    unsigned long long x, y;
    cin >> x >> y;
    int cnt = 0;
    while(true){
        x *= 2;
        if(x > y){break;}
        cnt++;
    }
    cout << cnt + 1 << endl;
}