#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
const ll MOD = 1000000007; 
using plong = pair<long,long>;


bool cmp(plong a,plong b){
    if(a.first!=b.first)return a.first<b.first;
    return a.second<b.second;
}


int main(){   
    ll N;
    cin>>N;
    vector<plong> red(N);
    vector<plong> blue(N);
 
    for(ll i=0;i<N;i++){
        long a,b;
        cin>>a>>b;
        red[i] = make_pair(a,b);
    }
    for(ll i=0;i<N;i++){
        long a,b;
        cin>>a>>b;
        blue[i] = make_pair(a,b);
    }
    sort(red.begin(),red.end(),cmp);
    sort(blue.begin(),blue.end(),cmp);
    ll res=0;
    ll index=0;
    for(ll i=0;i<N;i++){
            long max_y=-1;
        for(ll j=0;j<N;j++){
            if(red[j].first<blue[i].first&&red[j].second<blue[i].second){
                // cout<<"red:"<<red[j].first<<","<<red[j].second<<", blue:"<<blue[i].first<<","<<blue[i].second<<endl;
                max_y = max(max_y,red[j].second);
            }
            
        }
        if(max_y!=-1){
            for(ll k=0;k<N;k++){
                if(max_y==red[k].second){
                    res++;
                    // cout<<"red:"<<red[k].first<<","<<red[k].second<<", blue:"<<blue[i].first<<","<<blue[i].second<<endl;
                    // cout<<"AA"<<endl;
                    red[k].second = -2;
                    break;
                }
            }
        }
    }
    cout<<res<<endl;
}