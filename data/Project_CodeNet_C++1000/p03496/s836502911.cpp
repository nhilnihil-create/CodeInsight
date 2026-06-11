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

    int n;
    cin >> n;
    vector<int> a(n);
    int maxi=0;
    int mini=0;
    rep(i,n){
        cin >> a[i];
        if(a[maxi]<a[i]){
            maxi = i;
        }
        if(a[mini]>a[i]){
            mini = i;
        }
    }
    int cnt=0;
    vector<pair<int,int>> ans;

    cout << 2*n-1 << endl;

    if(abs(a[maxi])>abs(a[mini])){
        int x = a[maxi];
        rep(i,n){
            a[i]+=x;
            cout << maxi+1 << " " << i+1 << endl;
        }
        rep(i,n-1){
            a[i+1]+=a[i];
            cout << i+1 << " " << i+2 << endl;
        }
    }
    else{
        int x = a[mini];
        for(int i=n-1;i>=0;i--){
            a[i]+=x;
            cout << mini+1 << " " << i+1 << endl;
        }
        for(int i=n-1;i>0;i--){
            a[i-1]+=a[i];
            cout << i+1 << " " << i << endl;
        }

    }
    

    return 0;
}