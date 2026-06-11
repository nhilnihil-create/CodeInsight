#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b, t; cin >> a >> b >> t;

    int total =  t / a;
    total = b * total;

    
    cout << total << endl;
    

    return 0;
}