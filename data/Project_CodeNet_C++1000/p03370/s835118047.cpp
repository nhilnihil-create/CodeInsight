/* 
 * Project: AtCoder Beginners Contest 095 B - Bitter Alchemy
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/12
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;

int n, x;
int m[1000];

void solve() {

    int min_m = *min_element(m, m+n);
    int last = x - accumulate(m, m+n, 0);
    int sum = last / min_m + n;
    printf("%d\n", sum);

}

int main() {

    scanf("%d", &n);
    scanf("%d", &x);
    for (int i=0;i<n;i++) {
        scanf("%d", &m[i]);
    }

    solve();

}