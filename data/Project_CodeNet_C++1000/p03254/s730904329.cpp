#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long
int arr[105];
int main()
{
    int n, x;
    cin >> n >> x;

    ll min = 1000000005;
    ll totalsum = 0;
    int cnt = 1;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        totalsum = totalsum + arr[i];
        if (arr[i] < min){
            min = arr[i];
        }
    }
    
    sort(arr + 1, arr + n + 1);

    if (min > x){
        cout << "0" << endl;
        return 0;
    }
    
    if (totalsum == x){
        cout << n << endl;
    }
    
    else if (totalsum > x){
        int cntr = 0;
        int def = 1;
        while (def <= n){
            if (arr[def] <= x){
                cntr++;
                x = x - arr[def];
            }
            def++;

        }
        cout << cntr << endl;
    }
    
    else if (totalsum < x){
        cout << n-1 << endl;
    }
    return 0;
}

