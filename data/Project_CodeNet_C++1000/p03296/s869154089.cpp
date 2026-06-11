#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < n-1;i++){
        if(a[i] == a[i+1]){
            sum++;
            a[i+1] = 0;
        }
    }
    cout << sum;
} 