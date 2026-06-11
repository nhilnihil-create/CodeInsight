#include <bits/stdc++.h>

int main(){
    int X, Y, Z, K;
    std::cin >> X >> Y >> Z >> K;
    std::vector< long long > A(X);
    std::vector< long long > B(Y);
    std::vector< long long > C(Z);
    for(int i=0; i<X; i++){
        std::cin >> A[i];
    }
    for(int i=0; i<Y; i++){
        std::cin >> B[i];
    }
    for(int i=0; i<Z; i++){
        std::cin >> C[i];
    }
    
    std::priority_queue< long long > AB_pq;
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            AB_pq.push(A[i] + B[j]);
        }
    }
    
    int K_ab = std::min(K, X * Y);
    std::vector< long long > AB(K_ab);
    for(int i=0; i<K_ab; i++){
        AB[i] = AB_pq.top();
        AB_pq.pop();
    }
    
    
    std::priority_queue< long long > ABC_pq;
    for(int i=0; i<K_ab; i++){
        for(int j=0; j<Z; j++){
            ABC_pq.push(AB[i] + C[j]);
        }
    }
    
    for(int i=0; i<K; i++){
        std::cout << ABC_pq.top() << std::endl;
        ABC_pq.pop();
    }
    
    
    return 0;
}

