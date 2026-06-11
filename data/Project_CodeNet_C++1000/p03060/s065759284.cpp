#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int n, sum = 0;
    cin >> n;
    int arr1[n], arr2[n], arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }
    for(int i = 0; i < n; i++){
        arr[i] = arr1[i] - arr2[i];
        if(arr[i] > 0){
            sum = sum + arr[i];
        }
    }
    cout << sum;

}





///promy_pompom
//hello world
