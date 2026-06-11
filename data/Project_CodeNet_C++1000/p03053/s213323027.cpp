#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

template <typename T>
using TABLE = vector<vector<T>>;

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;


int main(){
    long long H, W;
    cin >> H >> W;

    TABLE<long long> A(H, vector<long long>(W, 0));
    string s;

    vector<pair<int, int>> v;
    for(int y = 0; y < H; ++y){
        cin >> s;
        for(int x = 0; x < W; ++x){
            if(s[x] == '.'){
                A[y][x] = 1;
            }
            else{
                v.push_back(pair<int, int>(y, x));
            }
        }
    }

    int count = 0;
    vector<pair<int, int>> v_sub;

    while(v.size()){
        v_sub.clear();
        for(auto& pos : v){
            int y = pos.first;
            int x = pos.second;

            if(y != 0 && A[y-1][x]){
                A[y-1][x] = 0;
                v_sub.push_back(pair<int, int>(y-1, x));
            }
            if(x != 0 && A[y][x-1]){
                A[y][x-1] = 0;
                v_sub.push_back(pair<int, int>(y, x-1));
            }
            if(y != H - 1 && A[y+1][x]){
                A[y+1][x] = 0;
                v_sub.push_back(pair<int, int>(y+1, x));
            }
            if(x != W - 1 && A[y][x+1]){
                A[y][x+1] = 0;
                v_sub.push_back(pair<int, int>(y, x+1));
            }
        }
        swap(v, v_sub);
        ++count;
    }

    cout << count - 1;
}
