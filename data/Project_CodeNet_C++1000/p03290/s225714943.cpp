#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define N 100001
#define ll long long
using namespace std;

struct Node{
    ll a;
    ll b;
};

int main(){
    int n;
    ll g;
    cin>>n>>g;
    
    struct Node data[n];
    
    for (int i=0; i<n; i++){
        cin>>data[i].a>>data[i].b;
    }
    

    
    vector<ll> ans;
    for (int bit = 0; bit < (1<<n); ++bit){
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i))  S.push_back(1);
            else S.push_back(0);
        }
        
        ll memo=0;
        ll sum=0;
        ll max=0;
        
        for (int i=0; i<n; i++){
            if (S[i]==1){
                sum+=100*(i+1)*data[i].a+data[i].b;
                memo+=data[i].a;;
            }
            else max=i;
        }
        
        if (sum>=g) ans.push_back(memo);
        else{
            ll p=g-sum;
            ll q=(data[max].a-1)*100*(max+1);
            ll r=(max+1)*100;
            if (p<=q){
                if (p%r==0) memo+=p/r;
                else memo+=p/r+1;
                ans.push_back(memo);
            }
        }
    }
    sort(ans.begin(),ans.end());
    
    cout<<ans[0]<<endl;
}