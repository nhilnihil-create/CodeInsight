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

int main(){
    ll n,k;
    cin>>n>>k;
    ll sum=0;
    
    if (k%2==1){
        ll count=0;
        for (ll i=1; i<=n; i++){
            if (i%k==0) count++;
        }
        sum=count*count*count;
    }
    
    else{
        ll count1=0;
        ll count2=0;
        for (ll i=1; i<=n; i++){
            if (i%k==0) count1++;
            if (i%k==k/2) count2++;
        }
        sum+=count1*count1*count1;
        sum+=count2*count2*count2;
    }
    
    cout<<sum<<endl;
}