#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int main(){
    int n, x, k;
    ll arr[105], sum=0;
    cin >> n >> x;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    if(x>sum){
        k=n-1;
    }
    else if(x<sum){
        sort(arr+1, arr+n+1);
        k=0;
        for(int i=1; i<=n; i++){
            if(x>=arr[i]){
                x-=arr[i];
                k++;
            }
        }
    }
    else{
        k=n;
    }
    cout << k << endl;
    return 0;
}