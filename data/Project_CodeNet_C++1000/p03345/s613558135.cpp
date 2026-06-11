#include<bits/stdc++.h>

int main(int argc, const char * argv[]) {
    long long int a,b,c,d;
    std::cin>>a>>b>>c>>d;
    if(d%2==0&&abs(a-b)<10000000000000000000){
        std::cout<<a-b<<std::endl;
    }else if(d%2==1 &&abs(a-b)<10000000000000000000){
        std::cout<<b-a<<std::endl;
    }else{
        std::cout<<"Unfair"<<std::endl;
    }
    return 0;
}
