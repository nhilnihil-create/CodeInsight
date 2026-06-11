/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2020
 */
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
typedef long long ll;

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A, P;
    cin >> A >> P;
    int pieces = A * 3 + P;
    cout << pieces / 2 << endl;
    return 0;
}

