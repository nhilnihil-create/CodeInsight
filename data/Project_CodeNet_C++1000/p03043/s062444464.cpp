#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm>
#include <iomanip>
using namespace std;
int main(void){
    std::cout<<std::fixed<<std::setprecision(10);
    long double n,k; cin >> n>> k;
    long double i = 1;
    long double ans = 0;
    while (i <= n) {
        long double count = 0;
        long double score = i;
        while (score < k) {
            score = score * 2;
            count++;
        }
        int j = 1;
        long double tmp = 0.5 * pow(10,10);
        while (j < count) {
            tmp = tmp * 0.5;
            j++;
        }
        if (i < k) ans += 1 / n * tmp / pow(10, 10);
        else ans += 1 / n;
        i++;
    }
    cout << ans << endl;
}