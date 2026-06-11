#include<iostream>
#include<utility>
int main(){
        int A,B,C;
        std::cin >> A >> B >> C;
        if(B > A) std::swap(A,B);
        if(C > A) std::swap(A,C);
        if(C > B) std::swap(B,C);
        std::cout << A*10 + B + C;
}