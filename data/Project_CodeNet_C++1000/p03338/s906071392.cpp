//
//  main.cpp
//  ABC_098_B
//
//  Created by Joe Mori on 2020/06/08.
//  Copyright © 2020 Joe Mori. All rights reserved.
//

//#include <iostream>
#include<bits/stdc++.h>
int main() {
    // insert code here...
    std::string str;
    int a;
    std::cin>>a;
    std::cin>>str;
    int c=0;
//    std::vector<std::string>b;
    int count=0,ans=0;
    for(int i=0;i<str.size()-1;i++){
        for(int j=0;j<=i;j++){
//            std::cout<<i<<"個:"<<j<<std::endl;
            for(int l=j;l>0;l--){
                if(str[j]==str[l-1]){
                    c=1;
                    break;
                }
            }
            if(c==1){
                c=0;
                continue;
            }
            for(int k=i+1;k<str.size();k++){
                if(str[j]==str[k]){
                    count++;
                    break;
                }
            }
        }
        ans=std::max(ans,count);
        count=0;
    }
    std::cout<<ans<<std::endl;
    return 0;
}
