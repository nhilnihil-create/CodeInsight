#include<stdio.h>
#include<iostream>
#include<string>
#include<memory>
#include<cmath>
#include<algorithm>
#include<vector>
int main(){
    std::string S;

    std::cin>>S;

    long long K;
    std::cin>>K;

    if(S.length()==1){
        std::cout<<S<<std::endl;
        return 0;
    }

    int count=0;

    for(int i=0;S[i]=='1';i++){
        count++;
    }

    //std::cout<<count<<std::endl;


    if(count>=K) std::cout<<"1"<<std::endl;
    else std::cout<<S[count]<<std::endl;

    return 0;
}