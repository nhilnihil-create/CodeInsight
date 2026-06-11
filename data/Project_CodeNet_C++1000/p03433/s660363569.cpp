/* 
 * Project: AtCoder Beginners Contest 088 A - Infinite Coins
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/01
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cmath>
using namespace std;

int n, a;

void solve() {
    if ((n % 500) <= a) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

}

int main() {

    scanf("%d", &n);
    scanf("%d", &a);

    solve();

}