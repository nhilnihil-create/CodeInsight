#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int input,s1,s2,s3,output = 0;
    cin >> input;
    s1 = input%10;
    input /= 10;
    s2 = input%10;
    input /= 10;
    s3 = input%10;
    input /= 10;
    if (s1 == 1) output++;
    if (s2 == 1) output++;
    if (s3 == 1) output++;
    cout << output << endl;
}

// vim: set fileencoding=utf-8
