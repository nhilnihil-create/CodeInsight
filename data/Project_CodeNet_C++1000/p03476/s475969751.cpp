//
//  main.cpp
//  ABC_084_D
//
//  Created by Joe Mori on 2020/06/12.
//  Copyright © 2020 Joe Mori. All rights reserved.
//

#include <iostream>
#include<bits/stdc++.h>
int main() {
    std::vector<int>a(100100,1);
    a[0]=0;
    a[1]=0;
    for(int i=2;i<a.size();i++){
        if(!a[i])continue;
        for(int j=2;j*i<a.size();j++){
            a[j*i]=0;
        }
    }
    std::vector<int>ans(100100,0);
    for(int i=3;i<a.size();i++){
        if(!a[i]){
            ans[i]=ans[i-1];
            continue;
        }
        if(a[i]==1&&a[(i+1)/2]==1){
            ans[i]=ans[i-1]+1;
            continue;
        }else ans[i]=ans[i-1];
    }
    int Q;
    std::cin>>Q;
    for(int i=0;i<Q;i++){
        int l,r;
        std::cin>>l>>r;
//        std::cout<<ans[r]<<" "<<ans[l]<<std::endl;
        std::cout<<ans[r]-ans[l-1]<<std::endl;
    }
    return 0;
}
