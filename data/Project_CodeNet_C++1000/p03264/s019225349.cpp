#include<cstdio>
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int sum=0;
    
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=a;j++)
        {
            if((i + j) % 2 == 0)
            {
                sum = sum + 0;
            }
            else
            {
                sum = sum + 1;
            }
        }
    }
    cout << sum/2;
}
