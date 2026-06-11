#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
    int N;
    cin >> N;
    string s[N];
    for(int i = 0; i < N; i++) cin >> s[i];

    vector<vector<char>> c(2 * N, vector<char>(2 * N));
    for(int i = 0; i < 2 * N; i++){
        for(int j = 0; j < 2 * N; j++){
            c[i][j] = s[i % N][j % N];
        }
    }

    int ans = 0;

    for(int i = 0; i < N; i++){
        bool check = true;

        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
                if(c[i + x][y] != c[i + y][x]) check = false;
            }
        }

        if(check){
            ans += N - i;
        }
    }

    for(int j = 1; j < N; j++){
        bool check = true;

        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
                if(c[x][j + y] != c[y][j + x]) check = false;
            }
        }

        if(check){
            ans += N - j;
        }
    }

    cout << ans << endl;
    return 0;
}