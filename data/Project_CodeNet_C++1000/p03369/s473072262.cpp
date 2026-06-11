/* 
 * Project: AtCoder Beginners Contest 095 A - Something on It
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/02
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

char s[3];

void solve() {

    int price = 700;
    for (int i=0;i<sizeof(s)/sizeof(char);i++) {
        if (s[i] == 'o') {
            price += 100;
        }
    }
    printf("%d\n", price);

}

int main() {

    scanf("%s", s);

    solve();

}