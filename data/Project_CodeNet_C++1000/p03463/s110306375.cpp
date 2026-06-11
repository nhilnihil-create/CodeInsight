#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b,c,f=0;
    cin >> n >> a >> b;
    c=abs(a-b);
    if(c%2==1) f=1;
    if(f==0) cout << "Alice" << endl;
    else cout << "Borys" << endl;
    return 0;
}