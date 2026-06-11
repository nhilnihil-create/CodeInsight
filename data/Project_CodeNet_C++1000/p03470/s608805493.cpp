#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<cmath>
#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
const unsigned int M = 1000000007;
using namespace std;
int removed(int arr[],int num)
{
    int i,j,k;
for(i=0; i<num; i++)
    {
        for(j=i+1; j<num; j++)
        {
            if(arr[i] == arr[j])
            {
                for(k=j; k<num; k++)
                {
                    arr[k] = arr[k + 1];
                }
 
                num--;
                j--;
            }
       }
    }
    return num;
}
int main()
{
int n,c; cin>>n; int a[n];
for(int i=0;i<n;i++) cin>>a[i];
sort(a,a+n); c=removed(a,n);
cout<<c;
return 0;
}