//
//  main.cpp
//  AGC_029_A
//
//  Created by Joe Mori on 2020/05/30.
//  Copyright © 2020 Joe Mori. All rights reserved.
//

#include <iostream>
#include<string>
int main() {
    long long int a,count=0,b=0;
    std::string str;
    std::cin>>str;
    a=str.length();
    int c=str.length();
    for(int i=0;i<c;i++){
        if(str[i]=='B'){
            b++;
        }else{
            count+=b;
        }
    }
    std::cout<<count<<std::endl;
    return 0;
}
