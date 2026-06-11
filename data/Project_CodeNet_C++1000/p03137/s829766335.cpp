#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <climits>

struct distance
{
    long dis;
    long town;
    distance(long dis1, long town1){
    dis=dis1;
    town=town1;
  }
  bool operator<( const distance &another ) const {
        return dis<another.dis;
  }
};

int main(){
    long N,M;
    std::cin >> N >> M;
    std::vector<long> X;
    for(long i=0; i<M; i++){
        long temp;
        std::cin >> temp;
        X.push_back(temp);
    }
    std::sort(X.begin(),X.end());
    if(M<=N){
        std::cout << 0 << std::endl;
        return 0;
    }
    std::vector<distance> dist;
    for(long i=1; i<M; i++){
        dist.push_back(distance(X[i]-X[i-1],i));
    }
    std::sort(dist.begin(),dist.end());
    

    long sum=X[M-1]-X[0];
    for(long i=0;i<N-1; i++){
        sum-=dist[(M-2)-i].dis;
    }

        std::cout << sum << std::endl;
    return 0;
}