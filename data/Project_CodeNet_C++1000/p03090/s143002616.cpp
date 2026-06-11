#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    int N;
    cin >> N;
    if(N % 2 == 0){
        ll count = 0;
        for(int i = 1; i < N + 1; i++){
            for(int j = i + 1; j < N + 1; j++){
                if(i + j == N + 1){
                    continue;
                }
                count++;
            }
        }
        cout << count << endl;
        for(int i = 1; i < N + 1; i++){
            for(int j = i + 1; j < N + 1; j++){
                if(i + j == N + 1){
                    continue;
                }
                cout << i << " " << j << endl;
            }
        }
    }else{
        ll count = 0;
        for(int i = 1; i < N + 1; i++){
            for(int j = i + 1; j < N + 1; j++){
                if(i + j == N){
                    continue;
                }
                count++;
            }
        }
        cout << count << endl;
        for(int i = 1; i < N + 1; i++){
            for(int j = i + 1; j < N + 1; j++){
                if(i + j == N){
                    continue;
                }
                cout << i << " " << j << endl;
            }
        }

    }

}
