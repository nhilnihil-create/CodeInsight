#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int H,W;
    cin >> H >> W;
    vector<vector<int>> vec(H,vector<int>(W));
    for(int i = 0;i < H;i++) {
        for(int j = 0;j < W;j++) {
            cin >> vec.at(i).at(j);
        }
    }
    vector<tuple<int,int,int,int>> ret;
    for(int i = 0;i < H;i++) {
        if(i % 2 == 0) {
            for(int j = 0;j < W - 1;j++) {
                if(vec.at(i).at(j) % 2 == 1) {
                    ret.push_back(make_tuple(i,j,i,j + 1));
                    vec.at(i).at(j + 1)++;
                }
            }
            if(i != H - 1 && vec.at(i).at(W - 1) % 2 == 1) {
                ret.push_back(make_tuple(i,W - 1,i + 1,W - 1));
                vec.at(i + 1).at(W - 1)++;
            }
        }
        else {
            for(int j = W - 1;j >= 1;j--) {
                if(vec.at(i).at(j) % 2 == 1) {
                    ret.push_back(make_tuple(i,j,i,j - 1));
                    vec.at(i).at(j - 1)++;
                }
            }
            if(i != H - 1 && vec.at(i).at(0) % 2 == 1) {
                ret.push_back(make_tuple(i,0,i + 1,0));
                vec.at(i + 1).at(0)++;
            }
        }
    }
    std::cout << ret.size() << endl;
    for(int i = 0;i < ret.size();i++) {
        std::cout << get<0>(ret.at(i)) + 1 << " " << get<1>(ret.at(i)) + 1 << " " << get<2>(ret.at(i)) + 1 << " " << get<3>(ret.at(i)) + 1 << endl;
    }
}