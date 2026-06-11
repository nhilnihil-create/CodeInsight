/* 
 * Project: AtCoder Beginners Contest 102 A - Multiple of 2 and N
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/07
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

int n;

void solve() {

    if (n & 1)
        printf("%d\n", n*2);
    else
        printf("%d\n", n);

}

int main() {

    scanf("%d", &n);

    solve();

}