#include<iostream>
#include<algorithm>
int main(){
        int A[3];
        std::cin >> A[0] >> A[1] >> A[2];
        std::cout<<std::max({A[0],A[1],A[2]}) - std::min({A[0],A[1],A[2]});
}