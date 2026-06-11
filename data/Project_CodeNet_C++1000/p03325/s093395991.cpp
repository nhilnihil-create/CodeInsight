#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[10000];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        while(arr[i]%2==0)
        {
            arr[i]/=2;sum++;
        }
    }
    cout<<sum;
}