#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,x;
    while(cin >> a >> b >> x){
        if(a>x){
            puts("NO");
        }
        else if(a+b-1>=x)puts("YES");
        else puts("NO");
    }
}
