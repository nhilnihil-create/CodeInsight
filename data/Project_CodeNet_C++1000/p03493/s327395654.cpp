#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int S;
    cin >> S;
    int s1, s2, s3;
    s3 = S % 10;
    s2 = (S  - s3) / 10 % 10;
    s1 = (S -s2*10 - s3) / 100 % 10;
    cout << s1 + s2 +s3 << endl;

}