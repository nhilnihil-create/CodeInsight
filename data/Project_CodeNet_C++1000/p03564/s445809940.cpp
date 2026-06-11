/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int min_val=1,c=0,d=0;
    for(int i=0;i<n;i++)
    {
        c=min_val*2;
        d=min_val+k;
        min_val=min(c,d);
    }
    cout<<min_val;

    return 0;
}
