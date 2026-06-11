#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#include <string>
#include <algorithm>


int main(){
    int n,x;cin >> n >> x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }


    int ans=0;

    sort(arr,arr+n);

    for(int i=0;i<n;i++){
        x=x-arr[i];
        if(x>=0)ans++;
        else break;
    }

    if(x>0&&ans>0) ans--;

    cout << ans << endl;

}