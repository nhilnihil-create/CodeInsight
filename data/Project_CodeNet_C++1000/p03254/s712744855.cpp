#include <iostream>
#include <algorithm>

using namespace std; 

int arr[1005];

void findMaxHappy(int n , int x){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(x >= arr[i]){
            if(i == n - 1 && (x - arr[i])!=0){
                cout << count << endl;
                exit(0);
            }
            else{
                count++; 
                x = x - arr[i]; // Update x value
            }
        }
    }
    cout << count << endl;
}

int main(){
    int n , x; 
    cin >> n >> x;

    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    sort(arr , arr + n); // Sort array

    findMaxHappy(n , x);
}