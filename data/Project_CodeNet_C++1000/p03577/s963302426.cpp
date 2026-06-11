#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
    cin>>a;
    int l=a.length();
    for(register int i=0;i<l-8;++i)putchar(a[i]);
    putchar('\n');
    return 0;
}