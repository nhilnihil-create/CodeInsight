/* 
 * Project: AtCoder Beginners Contest 102 B - Maximum Difference
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/07
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
int a[100];

void solve() {

    sort(a, a+n);
    int diff = a[n-1] - a[0];
    printf("%d\n", diff);

}

int main() {

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    solve();

}