#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,sum=0,i;
    cin >> n;
    int arr1[n];
    int arr2[n];
    for(i=0; i<n; i++)
        cin >> arr1[i];
    for(i=0; i<n; i++)
        cin >> arr2[i];
    for(i=0; i<n; i++)
    {
        if(arr1[i]>arr2[i])
        {
            sum+=arr1[i]-arr2[i];
        }
    }
    cout << sum;

}
