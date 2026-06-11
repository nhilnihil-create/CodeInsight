#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void solver1(int H, int W, vector<vector<char>> in_arg, vector<vector<int>> &return_arg){

    int l{}, r{}, u{}, d{};

    for(int h = 0; h != H; ++h){
        for(int w = 0; w != W; ++w){

            l = max(0, w-1);
            r = min(w+1, W-1);
            u = max(0, h-1);
            d = min(h+1, H-1);

            if(in_arg.at(h).at(w) == '#'){

                for(int i = u; i <= d; ++i){
                    for(int j = l; j <= r; ++j){

                        return_arg.at(i).at(j) += 1;
                    }
                }
            }
        }
    }

    return;
}

void solver2(int H, int W, vector<vector<char>> in_arg1, vector<vector<int>> in_arg2, vector<vector<char>> &return_arg){

    for(int h = 0; h != H; ++h){
        for(int w = 0; w != W; ++w){
            return_arg.at(h).at(w) = '0' + (in_arg2.at(h).at(w));
        }
    }

    for(int h = 0; h != H; ++h){
        for(int w = 0; w != W; ++w){
            if(in_arg1.at(h).at(w) == '#') return_arg.at(h).at(w) = '#';
        }
    }    

    return;
}

int main(){

    int H, W;
    cin >> H >> W;
    vector<vector<char>> area(H, vector<char>(W));
    for(int h = 0; h != H; ++h){
        for(int w = 0; w != W; ++w){
            cin >> area.at(h).at(w);
        }
    }

    vector<vector<int>> ans_int(H, vector<int>(W));
    vector<vector<char>> ans_char(H, vector<char>(W));
    solver1(H, W, area, ans_int);
    solver2(H, W, area, ans_int, ans_char);


    for(int h = 0; h != H; ++h){
        for(int w = 0; w != W; ++w){
            cout << ans_char.at(h).at(w);
        }
        cout << endl;
    }

    return 0;
}