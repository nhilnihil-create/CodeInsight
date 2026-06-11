#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
int main()
{
    long N;
    std::cin >> N;
    long T,A;
    std::cin >> T >> A;
    long H[1000+1];
    for(long i=1; i<=N; i++){
        std::cin >> H[i];
    }
    long index=1;
    double tmp=T-H[1]*0.006;
    for(long i=2; i<=N; i++){
        if(fabs(A-(T-H[i]*0.006))<fabs(A-tmp)){
            tmp=T-H[i]*0.006;
            index=i;
        }
    }
    std::cout << index << std::endl;
    return 0;
}