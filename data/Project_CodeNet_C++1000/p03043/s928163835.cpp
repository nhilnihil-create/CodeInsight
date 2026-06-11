#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;



int main(){
    double N, K;
    int n;
    cin >> N >> K;
    double exp = 0;
    for (n =1 ;n<=N;n++){
        exp += pow(0.5, fmax(0,ceil(log2(K/n))));
    }
    //exp +=N-K+1;
    std::cout << std::fixed;
    std::cout << std::setprecision(12);
    std::cout << (exp/N) <<endl;
    return 0;
}

