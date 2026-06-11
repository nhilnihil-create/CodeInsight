#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<numeric>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

using ll = long long;

class Stream{
public:
    Stream(){

    }
    //配列以外の入力を受け取る
    void read(){

    }
    template<typename First, typename... Rest>
    void read(First& first, Rest&... rest){
        cin >> first;
        read(rest...);
    }
    template<typename T>
    vector<T> read_vec(size_t n){
        vector<T> tmp(n);
        for(size_t i = 0; i < n; i++){
            cin >> tmp[i];
        }
        return tmp;
    }
    //配列を区切って出力する
    template<typename T>
    void write_vec(vector<T>& v, char divider){
        for(size_t i = 0; i < v.size(); i++){
            cout << v[i] << divider;
        }
    }
};

int main(){
    Stream io;

    int H, W;
    io.read(H, W);
    auto S = io.read_vec<string>(H);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#') continue;
            int sum = 0;
            for(int x = max(0, j - 1); x <= min(j + 1, W - 1); x++){
                for(int y = max(0, i - 1); y <= min(i + 1, H - 1); y++){
                    if(x == j && y == i) continue;
                    if(S[y][x] == '#') sum++;
                }
            }
            S[i][j] = sum + '0';
        }
    }
    for(int i = 0; i < H; i++){
        cout << S[i] << '\n';
    }
    return 0;
}