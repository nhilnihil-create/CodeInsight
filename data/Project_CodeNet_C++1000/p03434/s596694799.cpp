#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n,greater<int>());
    int alice,bob;
    alice=bob=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        alice+=arr[i];
        else
        bob+=arr[i];
    }
    cout<<alice-bob<<"\n";
}