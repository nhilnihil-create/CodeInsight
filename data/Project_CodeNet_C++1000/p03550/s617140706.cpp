#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,z,w;
    cin >> n >> z >> w;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    int ans = 0;
    int b,c,d,e,f;

    if (n==1){
        ans=abs(a[0]-w);
        cout << ans;
        return 0;
    }
    if (a[n-2]-a[n-1]!=0){
        c=abs(a[n-2]-a[n-1]);
    }
    else{
        c=0;
    }
    if(w-a[n-1]!=0){
        b=abs(w-a[n-1]);
    }
    else{
        b=0;
    }

    ans=max(c,b);

    cout << ans;



    return 0;
}