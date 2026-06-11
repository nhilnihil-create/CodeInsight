#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n],alice = 0,bob = 0;
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    sort(arr , arr+n,greater<int>());
    for(int i = 0;i<n;i++)
        {
            if(i&1)
                bob += arr[i];
            else alice += arr[i];
        }
        cout<<alice - bob<<endl;
    return 0;
}