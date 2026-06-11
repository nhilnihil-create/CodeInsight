#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <vector>
#include <iomanip>
#define rep(i,n) for(int i=0;i<(n);++i)

using namespace std;

typedef long long ll;




int main(){

    int N;
    cin>>N;

    string str;

    ll num[5];

    rep(i,5){
        num[i]=0;
    }

    for(int i=0;i!=N;++i){
        cin>>str;

        switch(str[0]){
            case 'M':
            num[0]++;
            break;
            case 'A':
            num[1]++;
            break;
            case 'R':
            num[2]++;
            break;
            case 'C':
            num[3]++;
            break;
            case 'H':
            num[4]++;
            break;
        }
    }

    ll ans=0;
/*
    rep(i,5){
        cout<<num[i]<<" ";
    }
    cout<<endl;
    */

    for(int i=0;i<=2;++i){
        for(int j=i+1;j<=3;++j){
            for(int k=j+1;k<=4;++k){
               // cout<<"num["<<i<<"]:"<<num[i]<<" num["<<j<<"]:"<<num[j]<<" num["<<k<<"]:"<<num[k]<<":"<<num[i]*num[j]*num[k]<<endl;
                ans+=num[i]*num[j]*num[k];
            }
        }
    }

    cout<<ans<<endl;
    
}
