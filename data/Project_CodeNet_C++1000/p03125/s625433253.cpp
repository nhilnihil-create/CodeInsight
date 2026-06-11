#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int a, b;
    cin >> a >> b;
    if(b % a == 0){
        cout << a + b;
    }
    else{
        cout << b - a;
    }


}
