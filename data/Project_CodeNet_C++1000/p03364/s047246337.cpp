#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
using namespace std;

string S[300];
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        bool is_good_grid = true;
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(S[(j - i + N) % N][k] != S[(k - i + N) % N][j]){
                    //cout << i << " " << j << " " << k << endl;
                    //cout << (j + i) % N << " " << k << endl;
                    //cout << S[(j + i) % N][k] << " " << S[k][(j + i) % N] << endl;
                    is_good_grid = false;
                    break;
                }
            }
            if(!is_good_grid){
                break;
            }
        }
        if(is_good_grid){
            ans += N;
        }
    }
    cout << ans << endl;
    return 0;
}
