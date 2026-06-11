#include <bits/stdc++.h>

int main(){
    int N, K;
    std::cin >> N >> K;
    std::vector< int > X(N);
    std::vector< int > Y(N);
    for(int i=0; i<N; i++){
        std::cin >> X[i] >> Y[i];
    }
    
    long long min = 4e18;
    for(int x1=0; x1<N; x1++){
        for(int x2=x1+1; x2<N; x2++){
            for(int y1=0; y1<N; y1++){
                for(int y2=y1+1; y2<N; y2++){
                    int xl = std::min(X[x1], X[x2]);
                    int xr = std::max(X[x1], X[x2]);
                    int yl = std::min(Y[y1], Y[y2]);
                    int yr = std::max(Y[y1], Y[y2]);
                    
                    int incnt = 0;
                    for(int i=0; i<N; i++){
                        if(X[i] >= xl && X[i] <= xr && Y[i] >= yl && Y[i] <= yr){
                            incnt++;
                        }
                    }
                    if(incnt >= K){
                        long long area = ((long long)xl - xr) * ((long long)yl - yr);
                        if(min > area){
                            min = area;
                        }
                    }
                }
            }
        }
    }
    
    std::cout << min << std::endl;
    
    
    return 0;
    
}
