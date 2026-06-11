#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    int arr[3];
    int i;
    int j;
    int ma  = INT_MIN;
    arr[0] = a + a - 1;
    arr[1] = b + b - 1;
    arr[2] = a + b;
    for(i=0;i<3;i++)
    {
        j = arr[i];
        ma = max(ma,j);
    }
    cout << ma;
}