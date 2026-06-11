/* 
 * Project: AtCoder Beginners Contest 113 B - Palace
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/09
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int t;
int a;
int h[1000];

void solve() {
    
    vector<int> diff;
    for (int i=0;i<n;i++) {
        diff.push_back(abs(t*1000 - h[i] * 6 - a*1000));
    }

    int min_idx = min_element(diff.begin(), diff.end()) - diff.begin();

    printf("%d\n", min_idx+1);

}

int main() {

    scanf("%d", &n);
    scanf("%d", &t);
    scanf("%d", &a);
    for (int i=0;i<n;i++) {
        scanf("%d", &h[i]);
    }

    solve();

}