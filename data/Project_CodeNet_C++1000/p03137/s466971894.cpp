#include<stdio.h>
#include<iostream>
#include<string>
#include<memory>
#include<cmath>
#include<algorithm>
#include<vector>
int main(){
    int num_piece,num_spot;
    std::cin>>num_piece>>num_spot;
    std::vector<int> x(num_spot);
    for(int i=0;i<num_spot;i++) std::cin>>x[i];
    if(num_piece >= num_spot){
        std::cout<< 0 <<std::endl;
        return 0;
    }
    std::sort(x.begin(),x.end());

    //for(int i=0;i<num_spot;i++) std::cout<<x[i]<<" ";
    //std::cout<<std::endl;

    int sumD=x[num_spot-1]-x[0];

    std::vector<int> dis(num_spot-1);

    for(int i=0;i<num_spot-1;i++) dis[i]=x[i+1]-x[i];

    std::sort(dis.begin(),dis.end());

    //for(int i=0;i<num_spot-1;i++) std::cout<<dis[i]<<" ";
    //std::cout<<std::endl;

    int district=0;
    for(int i=0;i<num_piece-1;i++) district+=dis[num_spot-2-i];

    //std::cout<<district<<std::endl;

    int ans=sumD-district;
    std::cout<<ans<<std::endl;

    return 0;
}

