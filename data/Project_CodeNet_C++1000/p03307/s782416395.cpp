#include<bits/stdc++.h>
using namespace std;
#define v  vector<int>
#define pb  push_back

int gcd(int a, int b)
{ return (b==0 ? a: gcd(b,a%b));}

int a;
int main()
{
    cin>>a;
    cout<<(a*2)/gcd(a,2);
}
