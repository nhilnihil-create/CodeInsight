#include<iostream>
int main(){
        int A,B;
        std::cin >> A >> B;
        int coin = 0;
        if(A  > B) coin += A--;
        else coin += B--;
        if(A  > B) coin += A;
        else coin += B;
        std::cout << coin;
}