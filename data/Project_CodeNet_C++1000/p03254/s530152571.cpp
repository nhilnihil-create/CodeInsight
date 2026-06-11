#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,x;
    cin >> n >> x;
    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum == x){
        cout << n << endl;
        return 0;
    }else if (sum < x){
        cout << n-1 << endl;
        return 0;
    }
    sort(a,a+n);
    int count = 0;
    for(int i = 0; i < n; i++){
        x -= a[i];
        if(x >= 0) count++;
        else break;
    }
    cout << count << endl;

    return 0;
}