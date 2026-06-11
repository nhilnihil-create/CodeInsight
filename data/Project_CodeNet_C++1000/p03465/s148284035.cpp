#include <bits/stdc++.h>

using namespace std;

bitset <5000000> bs;

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    int sum=0;
    bs[0]=1;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        bs|=bs<<arr[i];
        sum+=arr[i];
    }
    for(int i=(sum+1)>>1;;i++)
    {
        if(bs[i])
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
