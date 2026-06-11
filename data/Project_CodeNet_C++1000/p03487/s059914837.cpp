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

    rep(i,n){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    int cnt = 1;
    int ans = 0;
    int now = a[0];

    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            cnt+=1;
        }
        else{
            if(cnt<now){
                ans += cnt;
            }
            else{
                ans+=cnt-now;
            }
            now=a[i];
            cnt=1;
        }
    }
    if(cnt<now){
        ans += cnt;
    }
    else{
        ans+=cnt-now;
    }


    cout << ans;

    return 0;
}