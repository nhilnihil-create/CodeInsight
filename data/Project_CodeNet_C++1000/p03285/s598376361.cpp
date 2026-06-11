/* 
 * Project: AtCoder Beginners Contest 105 B - Cakes and Donuts
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/16
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

int n;

void solve() {
   
    const int cake = 4;
    const int donut = 7;

    int rem = n % cake;
    if (rem == 0 || rem == donut) {
        printf("Yes\n");
        return;
    }
    rem = rem % donut;
    if (rem == 0) {
        printf("Yes\n");
        return;
    }

    rem = n % donut;
    if (rem == 0 || rem == cake) {
        printf("Yes\n");
        return;
    }
    rem = rem % cake;
    if (rem == 0) {
        printf("Yes\n");
        return;
    }
    for (int i=1;i<n/cake;i++) {
        for (int j=0;j<n/donut;j++) {
            if (n == i*cake+j*donut) {
                printf("Yes\n");
                return;
            }
        }
    }
    printf("No\n");



}

int main() {

    scanf("%d", &n);

    solve();

}