#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n,h,w;
    cin >> n >> h >> w;
    int a[n],b[n];
    for(int i = 0;i < n;i++)cin >> a[i] >> b[i];
    int sum = 0;
    for(int i = 0;i < n;i++){
        if(a[i] >= h && b[i] >= w)sum++;
    }
    cout << sum;
}