#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n; cin >> n;
    int a[n+1];
    for(int i = 0; i < n; i++) cin >> a[i];
    a[n] = INT_MAX;
    int ans = 0, c = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == a[i+1]) c++;
        else {ans += (c+1)/2; c = 0;}
    }   
    cout << ans << endl;
    return 0;
}