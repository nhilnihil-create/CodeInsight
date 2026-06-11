#include <iostream>
#include <vector>

int main(void){

    int N;
    std::cin >> N;

    std::vector<int64_t> L(N+1);

    if (N == 1)
    {
        L.at(N)=1;
    }
    
    else 
    {
        L.at(0) = 2;
        L.at(1) = 1;
        for (int i = 2; i <= N; i++)
        {
            L.at(i) = L.at(i - 1) + L.at(i - 2);
        }
        
    }
    std::cout << L.at(N) << "\n";
    return 0;
}