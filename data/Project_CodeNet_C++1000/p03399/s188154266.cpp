#include<iostream>
int main(){
    int A,B,C,D;
    std::cin >> A >> B >> C >> D;
    int cost  = (A < B ? A : B);
    cost += (C < D ? C : D);
    std::cout << cost;
}