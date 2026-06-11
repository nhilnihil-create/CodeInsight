#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int h[N];
int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>h[i];
    sort(h,h+n);
    int mini=1e9+5;
    for(int i=0;i<n-m+1;i++){
        mini=min(mini,h[i+m-1]-h[i]);
    }
    cout<<mini;
    return 0;
}
