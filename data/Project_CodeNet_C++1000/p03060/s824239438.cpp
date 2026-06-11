#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    int ans =0;
    int arr[t],arr1[t];
    for (int x=0;x<t;x++) cin >> arr[x];
    for (int x=0;x<t;x++) cin >> arr1[x];
    for (int x=0;x<t;x++){
        int a= arr[x] , b= arr1[x];
        if (a-b>0) ans+= a-b;
    }
    cout << ans << endl;
}
