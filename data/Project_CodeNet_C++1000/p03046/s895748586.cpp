typedef unsigned long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll m,k;
    std::cin >> m>>k;
    
    if(m==0){
        if(k==0){
            std::cout << "0 0" << std::endl;
        }else{
            std::cout << -1 << std::endl;
        }
    }else if(m==1){
        if(k==0){
            std::cout << "0 1 1 0" << std::endl;
        }else{
            std::cout << -1 << std::endl;
        }
    }else{
        if(k<pow(2,m)){
            for (int i = 0; i < pow(2,m); i++) {
                if(i==k)continue;
                std::cout << i<<" ";
            }
            std::cout << k<<" ";
            for (int i = pow(2,m)-1; i>=0; i--) {
                if(i==k)continue;
                std::cout << i<<" ";
            }
            std::cout << k << std::endl;
        }else{
            std::cout << -1 << std::endl;
        }
    }
}
