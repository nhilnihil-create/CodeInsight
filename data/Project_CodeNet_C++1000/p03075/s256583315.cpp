#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[5],k;
    for(int i=0; i < 5; ++i) cin >> arr[i];
    cin>>k;
    sort(arr,arr+5);

    for(int i = 0; i < 4; ++i){
        for(int j = i+1; j < 5; ++j){
            if(abs(arr[i]-arr[j])>k){
                cout << ":(";
                return 0;
            }
        }
    }
    cout << "Yay!";
    return 0;
}
