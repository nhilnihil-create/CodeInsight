#include<bits/stdc++.h>
using namespace std;
double n,m,d;
int main()
{
    cin>>n>>m>>d;
    printf("%.10f\n",(d==0?1:2)*(n-d)*(m-1)/n/n);
}
