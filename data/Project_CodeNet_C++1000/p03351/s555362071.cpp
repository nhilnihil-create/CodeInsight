using namespace std;
#include <bits/stdc++.h>
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(abs(a-b)<=d){
        if(abs(b-c)<=d){
            std::cout << "Yes" << std::endl;
        }
        else{
            std::cout << "No" << std::endl;
        }
    }
    else if(abs(a-c)<=d){
        std::cout << "Yes" << std::endl;
    }
    else{
        std::cout << "No" << std::endl;
    }
    return 0;
}