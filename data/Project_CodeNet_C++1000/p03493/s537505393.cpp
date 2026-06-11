#include<cstdio>
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    int a;
    cin >> a ;
    int c = (a%100)%10;
    int d = a/100;
    int e = (a/10)%10;
    
    cout << c + d + e;
}


