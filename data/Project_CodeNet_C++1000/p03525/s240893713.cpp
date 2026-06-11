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
    int bucket[13];
    for(int i = 0; i < 13; i++){
        bucket[i] = 0;
    }
    bucket[0]++;
    for(int i = 0;i < N; i++){
        int tmp;
        cin >> tmp;
        bucket[tmp]++;
    }
    int pos[24];
    for(int i = 0; i < 24; i++){
        pos[i] = 0;
    }
    pos[0] = bucket[0];
    pos[12] = bucket[12];
    if(pos[0] == 2 || pos[12] == 2){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i < 12; i++){
        if(bucket[i] == 0){
            continue;
        }else if(bucket[i] == 1){
            int rm = 100;
            int lm = 100;
            for(int j = 0;j < i; j++){
                if(pos[j] != 0){
                    rm = i - j;
                }
                if(pos[(24 - j) % 24] != 0){
                    lm = i - j;
                }
            }
            if(rm > lm){
                pos[i] = 1;
            }else{
                pos[24 - i] = 1;
            }
        }else if(bucket[i] == 2){
            pos[i] = 1;
            pos[24 - i] = 1;
        }else{
            cout << 0 << endl;
            return 0;
        }
    }

    int m = 50;
    for(int i = 0; i < 24; i++){
        for(int j = 0; j < 24; j++){
            if(pos[i] == 0 || i == j){
                continue;
            }
            if(pos[j] != 0){
                m = min(m, min(abs(j - i),24 - abs(j - i)));
            }
        }
    }
    cout << m << endl;
}
