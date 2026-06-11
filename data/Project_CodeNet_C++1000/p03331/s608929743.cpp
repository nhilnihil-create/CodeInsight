#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
using namespace std;

int sum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int n, min = -1;
    cin >> n;
    for (int a = 1; a < n; a++)
    {
        int b = n - a;
        int sum_ = sum(a) + sum(b);
        if (min == -1 || min > sum_) min = sum_;
    }
    cout << min << endl;
}