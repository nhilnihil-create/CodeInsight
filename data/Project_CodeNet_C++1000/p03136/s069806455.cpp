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
    sort(arr, arr+n);
    for(int i = 0; i < n-1; i++){
        sum = sum + arr[i];
    }
    if(arr[n-1] < sum){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

}





///promy_pompom
//hello world
