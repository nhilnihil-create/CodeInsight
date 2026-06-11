#include<stdio.h>
#include<iostream>
#include<string>
#include<memory>
#include<cmath>
#include<algorithm>
#include<vector>
void swap(int *x,int *y){
    int tmp;
    tmp=*x;
    *x=*y;  
    *y=tmp;
}

int gcd(int a,int b){
    if(a<b) swap(&a,&b);
    if(b<1) return -1;

    if(a%b==0) return b;
    return gcd(b,a%b);
}


int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);

    int flag=0;

    for(int i=0;i<N;i++) std::cin>>vec[i];
    
    std::vector<int> left(N);
    std::vector<int> right(N);

    for(int i=0;i<N;i++){
        if(i==0) left[i]=vec[i];
        else left[i]=gcd(left[i-1],vec[i]);
    }
    //left[0]=0;

    for(int i=N-1;0<=i;i--){
        if(i==N-1) right[i]=vec[i];
        else right[i]=gcd(right[i+1],vec[i]);
    }
    //right[N-1]=0;

    /*
    for(int i=0;i<N;i++) std::cout<<left[i]<<" ";
    std::cout<<std::endl;
    for(int i=0;i<N;i++) std::cout<<right[i]<<" ";
    std::cout<<std::endl;
    */

    int max=0;
    int SUM=0;
    for(int i=0;i<N;i++){
        if(i==0) SUM=right[i+1];
        else if(i==N-1) SUM=left[i-1];
        else SUM=gcd(left[i-1],right[i+1]);
        if(max<SUM) max=SUM;
        //std::cout<<SUM<<std::endl;
    }

    std::cout<<max<<std::endl;


    return 0;
}

