#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <climits>

int main(){
    long N;
    std::cin >> N;
    long h[100];
    for(long i=0; i<N; i++){
        std::cin >> h[i];
    }
    long count=0;
    while(1){
        long l=0;
        long r=N;

        for(long i=0; i<N; i++){
            if(h[i]!=0){
                l=i;
                break;
            }
        }

        for(long j=l+1; j<N; j++){
            if(h[j]==0){
                r=j;
                break;
            }
        }

        long counts=0;
        for(long i=0; i<N; i++){
            if(h[i]==0){
                counts++;
            }
        }
        if(counts==N){
            break;
        }
        for(long i=l; i<r; i++){
            h[i]-=1;
        }
        count++;
    }
    std::cout << count << std::endl;
    return 0;
}