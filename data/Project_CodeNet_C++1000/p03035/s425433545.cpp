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
    int A, B;
    cin >> A >> B;
    if(A >= 13) cout << B;
    else if (6 <= A && A <= 12) cout << B / 2;
    else cout << 0;
    cout << endl;
    return 0;
    
}

