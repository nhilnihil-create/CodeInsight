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

    int prime[100000]={};

    for(int i=2;i*i<=100000;i++){
        if(!prime[i]){
            for(int j=2;i*j<=100000;j++){
                prime[i*j]=1;
            }
        }
    }

    ll exprime[100000]={};
    for(int i=3;i<=100000;++++i){
        if(!prime[i]){
            int m = (i+1)/2;
            if(!prime[m]){
                exprime[i]=1;
            }
        }
    }

    ll cnt[100000]={};
    for(int i=2;i<=100000;i++){
        if(exprime[i]){
            cnt[i]=cnt[i-1]+1;
        }
        else{
            cnt[i]=cnt[i-1];
        }
    }

    prime[0]=1;
    prime[1]=1;

    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << cnt[r] - cnt[l-1] << endl;
    }

    // rep(i,20){
    //     cout << prime[i] << " "<< exprime[i] << endl;
    // }


    return 0;
}