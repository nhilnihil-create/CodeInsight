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
    char m[N][N];
    for(int yi = 0; yi < N; yi++){
        string s;
        cin >> s;
        for(int xi = 0; xi < N; xi++){
            m[yi][xi] = s[xi];
        }
    }
    int count = 0;
    for(int i = 0; i < N; i++){
        bool judge = true;
        for(int yi = 0; yi < N; yi++){
            for(int xi = 0; xi < N; xi++){
                int X = (xi + i) % N;
                int Y = (yi + i) % N;
                //cout << m[X][yi] << m[Y][xi] << ",";
                if(m[X][yi] != m[Y][xi]){
                    judge = false;
                }
            }
        }
        //cout << endl;
        if(judge){
            count++;
        }
    }
    cout << count * N << endl;

}