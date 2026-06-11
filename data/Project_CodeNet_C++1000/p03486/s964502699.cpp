/* 
 * Project: AtCoder Beginners Contest 086 B - Two Anagrams
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/01
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

string s;
string t;

void solve() {

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    if (s < t)
        printf("Yes\n");
    else
        printf("No\n");

}

int main() {

    cin >> s >> t;

    solve();

}