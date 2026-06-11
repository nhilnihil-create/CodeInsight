#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    for(int i = 0; i < H; i++){
        cin >> s.at(i);
    }
    
    bool can2 = true;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(s.at(i).at(j) == '#'){
                bool can = false;
                if(i - 1 >= 0){
                    if(s.at(i - 1).at(j) == '#'){
                        can = true;
                    }
                }
                if(i + 1 <= H - 1){
                    if(s.at(i + 1).at(j) == '#'){
                        can = true;
                    }
                }
                if(j - 1 >= 0){
                    if(s.at(i).at(j - 1) == '#'){
                        can = true;
                    }
                }
                if(j + 1 <= W - 1){
                    if(s.at(i).at(j + 1) == '#'){
                        can = true;
                    }
                }
                if(can == false){
                    can2 = false;
                    break;
                }
            }
        }
    }
    
    if(can2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    


}