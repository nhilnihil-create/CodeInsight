#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int n,m,x;cin >> n >> m >>x;

    int arr[m];
    for(int i=0;i<m;i++){
        cin >> arr[i];
    }

    int cost = 0;
    int current = x;

    for(int i=0;i<x;i++){
        for(int j=0;j<m;j++){
            if(arr[j]==i) cost ++;
        }
    }

    int cost2 = 0;
    for(int i=x;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[j]==i) cost2 ++;
        }
    }


    int ans = min(cost,cost2);
    cout << ans << endl;
}