#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int n, sum = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n, greater<int>());
    arr[0] = arr[0]/2;
    for(int i = 0; i < n; i++){
        sum = sum + arr[i];
    }
    cout << sum;

}





///promy_pompom
//hello world
