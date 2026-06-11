#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b, c, d, e, k; cin >> a >> b >> c >> d >> e >> k;
    bool there = false;

    if((b - a) > k)
        there = true;
    if((c - a) > k)
        there = true;
    if((d - a) > k)
        there = true;
    if((e - a) > k)
        there = true;
    if((c - b) > k)
        there = true;
    if((d - b) > k)
        there = true;
    if((e - b) > k)
        there = true;
    if((d - c) > k)
        there = true;
    if((e - c) > k)
        there = true;
    if((e - d) > k)
        there = true;


    if(there)
        cout << ":(\n";
    else
        cout << "Yay!\n";
    
    
    return 0;
}