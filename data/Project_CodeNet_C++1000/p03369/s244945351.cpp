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
#include <cstring>
using namespace std;

char s[3];

void solve() {

    if (!strcmp(s, "ooo")) {
        printf("1000\n");
    } else if (!strcmp(s, "oox")) {
        printf("900\n");
    } else if (!strcmp(s, "oxo")) {
        printf("900\n");
    } else if (!strcmp(s, "oxx")) {
        printf("800\n");
    } else if (!strcmp(s, "xoo")) {
        printf("900\n");
    } else if (!strcmp(s, "xox")) {
        printf("800\n");
    } else if (!strcmp(s, "xxo")) {
        printf("800\n");
    } else if (!strcmp(s, "xxx")) {
        printf("700\n");
    }

}

int main() {

    scanf("%s", s);

    solve();

}