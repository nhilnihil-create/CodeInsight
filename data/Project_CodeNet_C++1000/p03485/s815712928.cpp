/* 
 * Project: AtCoder Beginners Contest 086 A - Round Up the Mean
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

int a, b;

void solve() {

    int average = (a + b + 1) >> 1;
    printf("%d\n", average);

}

int main() {

    scanf("%d", &a);
    scanf("%d", &b);

    solve();

}