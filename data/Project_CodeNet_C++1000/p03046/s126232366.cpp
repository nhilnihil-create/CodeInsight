//
//  main.cpp
//  F
//
//  Created by 曾憲揚 on 2020/9/7.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int powe(int k){
    int ans=1;
    for(int i=1; i<=k; i++)
        ans*=2;
    return ans;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m, k; cin>>m>>k;
    if(k>=powe(m))
        cout<<"-1\n";
    else if(m==1){
        if(k==0){
            cout<<"0 1 1 0\n";
        }
        else if(k==1){
            cout<<"-1\n";
        }
    }
    else{
        for(int i=0; i<(1<<m); i++){
            if(i==k) continue;
            else cout<<i<<" ";
        }
        cout<<k<<" ";
        for(int i=(1<<m)-1; i>=0; i--){
            if(i==k) continue;
            else cout<<i<<" ";
        }
        cout<<k<<endl;
    }
    return 0;
}
