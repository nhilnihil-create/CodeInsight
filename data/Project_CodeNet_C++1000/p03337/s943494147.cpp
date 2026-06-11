#include<iostream>
int main(){
        int A,B;
        std::cin >> A >> B;
        float max = A + B;
        if(max < A - B) max = A - B;
        if(max < A*B) max = A*B;
        std::cout<<max;
}
