#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,k;
    cin >> a >> b >> k;

    for(int i=a;i<=b;i++){
        if(a+k<=i && i<=b-k) continue;
        cout << i << endl;
    }
}