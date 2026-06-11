#include <bits/stdc++.h>

int max = 55555;

int main(){
    int N;
    std::cin >> N;
    std::vector< int > P;
    std::vector< bool > Pb(max+1, true);
    int cnt = 0;
    for(int i=2; i<=max; i++){
        if(Pb[i]){
            P.push_back(i);
            if(i % 5 == 1){
                std::cout << i << std::endl;
                cnt++;
                if(cnt == N){
                    return 0;
                }
            }
            for(int j=i+i; j<=max; j+=i){
                Pb[j] = false;
            }
        }
    }
    
    
    return 0;
    
}
