/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2020
 */
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int a = stoi(s.substr(0, 2)), b = stoi(s.substr(2));
    if (1 <= a && a <= 12 && 1 <= b && b <= 12) cout << "AMBIGUOUS";
    else if (1 <= a && a <= 12) cout << "MMYY";
    else if (1 <= b && b <= 12) cout << "YYMM";
    else cout << "NA";
    cout << endl;
    return 0;
}

