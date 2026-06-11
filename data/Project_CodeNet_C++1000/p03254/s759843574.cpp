#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n, x;
    cin >> n >> x;
    vector<int> a(n);
    ll s=0;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        s += a[i];
    }
    
    if(s==x){
        cout << n;
        return 0;
    }
    else if(x > s){
        cout << n-1;
        return 0;
    }

    sort(a.begin(), a.end());

    int count=0;
    for(int i=0; i<n; ++i){
        if(a[i] <= x){
            count++;
            x -= a[i];
        }
        else
            break;
    }
    cout << count;
}
