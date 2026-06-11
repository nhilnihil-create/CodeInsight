#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;

    int ans = 0;

    std::cin >> N;
    vector<int> V(N), C(N);

    for(int i = 0; i < N; i++){
        std::cin >> V[i];
    }
    for(int i = 0; i < N; i++){
        std::cin >> C[i];
    }

    for(int i = 0; i < N; i++){
        if(V[i] - C[i] > 0){
            ans = ans + V[i] - C[i];
        }
    }

    std::cout << ans;
}