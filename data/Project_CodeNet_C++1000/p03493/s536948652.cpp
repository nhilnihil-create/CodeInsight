#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int count = 0;
    if(s1 == '1') count++;
    if(s2 == '1') count++;
    if(s3 == '1') count++;

    cout << count << endl;
}