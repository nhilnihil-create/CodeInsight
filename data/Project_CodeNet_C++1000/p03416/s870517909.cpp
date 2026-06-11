#include <bits/stdc++.h>
using namespace std;

int rev(int x)
{
    int temp = 0;
    while(x) {
        (temp *= 10) += x %10;
        x /= 10;
    }
    return temp;
}

int main()
{
    int a, b, cnt = 0; cin >> a >> b;
    for( ; a <= b; a++) {
        if(a == rev(a)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
