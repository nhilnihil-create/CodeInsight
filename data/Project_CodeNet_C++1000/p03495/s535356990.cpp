#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n);i++)
using ll = long long;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n],x=0,b[n];
    rep(i, n){
        b[i] = 0;
        cin >> a[i];
    }
    sort(a, a + n);
    rep(i, n)
    {
        if (i == 0)
            x++;
        if (a[i] > a[i - 1])
            x++;
        b[a[i]-1]++;
    }
    sort(b, b + n);
    //0 conti n-x times
    
    if (x<=k)
        cout << 0 << endl;
    else{
        int y = 0;
        rep(i,x-k){
            y += b[n - x + i];
        }
        cout << y << endl;
    }
}