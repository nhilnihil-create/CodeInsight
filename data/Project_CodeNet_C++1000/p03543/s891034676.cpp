#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, a, b, c, d;
    cin >> N;
    a = N % 10;
    b = (N % 100 - N % 10) / 10;
    c = (N % 1000 - N % 100) / 100;
    d = (N - N % 1000) / 1000;

    if((a == b && a == c)||(b == c && b == d)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}