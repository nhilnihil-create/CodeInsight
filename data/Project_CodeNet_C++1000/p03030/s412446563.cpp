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
    vector<pair<string,pair<int,int>>> a(n);
    rep(i,n){
        string s;
        int q;
        cin >> s >> q;
        a[i].first=s;
        a[i].second.first=-q;
        a[i].second.second=i+1;
    }
    sort(a.begin(),a.end());
    // bool frag = false;
    // int cnt=0;
    // rep(i,n){
    //     if(!frag){
    //         if(a[i-1].first==a[i].first){
    //             cnt=2;
    //             frag = true;
    //         }
    //         else{
    //             continue;
    //         }
    //     }
    //     else{
    //         if(a[i-1].first==a[i].first){
    //             cnt++;
    //         }
    //         else{
    //             rep(j,cnt/2){
    //                 // cout << 4444<<endl;
    //                 swap(a[i-1-j].second.second,a[i-cnt+j].second.second);
    //             }
    //             frag=false;
    //             cnt=0;
    //         }
    //     }
    // }
    // if(frag){
    //     rep(j,cnt/2){
    //         swap(a[n-1-j].second.second,a[n-cnt+j].second.second);
    //     }
    // }
    rep(i,n){
        cout << a[i].second.second << endl;
    }
    
    return 0;
}