/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int N, D, X;

int a[101];


int chocolatePerStudent(int t)
{
    int res = 0;
    
    for(int act = 1 ; act <= D; act += t)
    {
        res ++;
    }
    return res;
}
int main()
{
    cin >> N >> D >> X;
    
    int n = N;
    
    while(n--)
    {
        cin >> a[N- n -1];
    }
    
    int consumed = 0;
    for(int i = 0; i < N; ++i)
    {
        consumed += chocolatePerStudent(a[i]);
    }
    
    cout << consumed + X;
    
    return 0;
}


