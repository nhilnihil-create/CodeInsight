#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
char s[] = "1001010111001010";
int main()
{
    long long i,n,x,y,c1=0,c2=0;
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>i>>n>>x;
    if(i+n>=x)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
