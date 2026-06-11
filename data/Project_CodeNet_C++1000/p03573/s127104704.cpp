/* 
 * Project: AtCoder Beginners Contest 075 A - One out of Three
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/29
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

int a;
int b;
int c;

void solve() {

    if (!(a ^ b))
        printf("%d\n", c);
    else if (!(b ^ c))
        printf("%d\n", a);
    else if (!(c ^ a))
        printf("%d\n", b);

}

int main() {

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    solve();

}