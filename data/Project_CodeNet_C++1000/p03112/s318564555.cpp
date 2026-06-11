#include <bits/stdc++.h>

int main(){
    int A, B, Q;
    std::cin >> A >> B >> Q;
    std::vector< long long > S(A);
    std::vector< long long > T(B);
    std::vector< long long > X(Q);
    for(int i=0; i<A; i++){
        std::cin >> S[i];
    }
    for(int i=0; i<B; i++){
        std::cin >> T[i];
    }
    for(int i=0; i<Q; i++){
        std::cin >> X[i];
    }
    
    for(int i=0; i<Q; i++){
        int leftS = 0;
        int rightS = A;
        if(A == 1){
            rightS = 0;
        }else{
            while(!(leftS == rightS-1)){
                int mid = (rightS + leftS) / 2;
                if(S[mid] > X[i]){
                    rightS = mid;
                }else{
                    leftS = mid;
                }
            }
        }
        if(rightS == A){
            rightS -= 1;
        }
        //std::cout<<"a"<<leftS<<" "<<rightS<<std::endl; 
        
        int leftT = 0;
        int rightT = B;
        if(B == 1){
            rightT = 0;
        }else{
            while(!(leftT == rightT-1)){
                int mid = (rightT + leftT) / 2;
                if(T[mid] > X[i]){
                    rightT = mid;
                }else{
                    leftT = mid;
                }
            }
        }
        if(rightT == B){
            rightT -= 1;
        }
        
        std::vector< long long > dist(8);
        dist[0] = std::abs(S[leftS] - X[i]) + std::abs(S[leftS] - T[leftT]);
        dist[1] = std::abs(S[leftS] - X[i]) + std::abs(S[leftS] - T[rightT]);
        dist[2] = std::abs(S[rightS] - X[i]) + std::abs(S[rightS] - T[leftT]);
        dist[3] = std::abs(S[rightS] - X[i]) + std::abs(S[rightS] - T[rightT]);
        dist[4] = std::abs(T[leftT] - X[i]) + std::abs(T[leftT] - S[leftS]);
        dist[5] = std::abs(T[leftT] - X[i]) + std::abs(T[leftT] - S[rightS]);
        dist[6] = std::abs(T[rightT] - X[i]) + std::abs(T[rightT] - S[leftS]);
        dist[7] = std::abs(T[rightT] - X[i]) + std::abs(T[rightT] - S[rightS]);
        std::sort(dist.begin(), dist.end());
        std::cout << dist[0] << std::endl;
    }
    
    
    return 0;
    
}
