#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    int arr[t], sum=0;
    for(int i=0; i<t; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
    sort(arr, arr+t);
    
    sum = sum - arr[t-1];
    if(arr[t-1]>=sum) cout << "No" << endl;
    else cout << "Yes" << endl;
    
	return 0;
}