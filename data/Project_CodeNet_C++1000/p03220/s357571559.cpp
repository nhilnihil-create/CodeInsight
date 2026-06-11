#include <bits/stdc++.h>

using namespace std;

int main() {
    /* code */
    double A, B, C, D, E;
    cin >> A >> B >> C;
    double ans = (B - C)/0.006;//嬉しい標高
    double pin = 10000000;//現時点最高の標高差
    int memo;
    for (size_t i = 0; i < A; i++)
    {
        cin >> D;//もらった標高
        if (abs(D-ans)<pin)//
        {
            /* code */
            pin = abs(D-ans);
            memo = i+1;
        }
        
    }
    cout << memo << endl;
    return 0;
}