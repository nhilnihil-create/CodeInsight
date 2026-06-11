#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m>> x;
    int a[m];
    rep(i, m) cin >> a[i];

    int left=0, right=0;
    for(int i=0; i<m; i++){ // 左側の探索
        if(a[i]>0 && a[i]<x)
            left++;
        if(a[i]>x && a[i]<n)
            right++;
    }
    
    if(left > right)
        cout << right << endl;
    else 
        cout << left << endl;
    return 0;
}