#include <iostream>
#include <vector>
#include <algorithm>

constexpr int INF = 1145141919;

int main(){
	std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int N, M, C;
    std::cin >> N >> M >> C;

    std::vector<std::vector<int>> A(N, std::vector<int>(M));
    std::vector<int> B(M);

    for(int i=0; i<M; i++){
        std::cin >> B.at(i);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            std::cin >> A.at(i).at(j);
        }
    }

    int count=0;
    for(int i=0; i<N; i++){
        int buf=C;
        for(int j=0; j<M; j++){
            buf = buf + A[i][j]*B[j];
        }
        if(buf>0){
            count++;
        }
    }

    std::cout << count;

    return 0;
}
