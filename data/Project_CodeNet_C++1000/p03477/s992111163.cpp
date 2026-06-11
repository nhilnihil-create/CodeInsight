/* 
 * Project: AtCoder Beginners Contest 083 A - Libra
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/26
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

int a, b, c, d;

void solve() {

    int weight_left  = a + b;
    int weight_right = c + d;
    if (weight_left == weight_right) {
        printf("Balanced\n");
        return;
    }
    if (weight_left > weight_right) {
        printf("Left\n");
        return;
    }
    if (weight_left < weight_right) {
        printf("Right\n");
        return;
    }

}

int main() {

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    solve();

}