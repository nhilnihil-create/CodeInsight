#include <algorithm>
#include <iostream>
#include <string>
 
#include <vector>
#include <cmath>
#include <limits>
#include <functional>
using namespace std;
 
int main()
{
    int N,X;
    cin >> N;
    int f = 0;
    int ans = 0, amari;
 
    X = N;
 
    while (N != 0)
    {
        amari = N % 10;
        f += amari;
        N = N / 10;
    }
 
    if (X % f==0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
 
    
 
    return 0;
}