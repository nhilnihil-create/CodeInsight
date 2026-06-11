#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a; cin >> a;
    int b; cin >> b;
    int s_b = 0;
    for (int i=1; i<=b-a; ++i){
        s_b += i;
    }
    cout << s_b - b << endl;
}
