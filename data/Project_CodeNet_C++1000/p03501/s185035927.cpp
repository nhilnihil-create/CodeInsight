#include<bits/stdc++.h>
using namespace std;
int main()
{ long long n,a,b,x;
cin>>n>>a>>b;
if((n*a)<b)
x=n*a;
if((n*a)>b) x=b ;
if((n*a)== b) x=b;

cout << x << "\n" ;

    return 0;
}
