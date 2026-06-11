#include<bits/stdc++.h>
using namespace std;
int main()
{
    long a,b,s;
    while(cin >> a >> b){
        s = a*b;
        if(s%2)puts("Odd");
        else puts("Even");
    }
    return 0;
}
