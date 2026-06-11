#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x;
    cin >> n >> m >> x;
    int a[m];
    int r=0;
    int l=0;
    for(int i=0;i<m;i++){
        cin >> a[i];
        if(a[i]<x)l++;
        else r++;
    }
    if(l>r)cout << r << endl;
    else cout << l << endl;
}