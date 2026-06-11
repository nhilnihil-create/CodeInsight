#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int h,w;
    cin >> h >> w;
    int math[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> math[i][j];
        }
    }    
    vector<pair<pair<int,int>,pair<int,int>>> ans;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(math[i][j]%2 == 1){
                if(j == w-1 && i == h-1) continue;
                else if(j == w-1 && i < h-1){
                    math[i][j]--;
                    math[i+1][j]++;
                    ans.push_back({{i+1,j+1},{i+2,j+1}});
                }
                else{
                    math[i][j]--;
                    math[i][j+1]++;
                    ans.push_back({{i+1,j+1},{i+1,j+2}});
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(auto p:ans){
        cout << p.first.first << " " << p.first.second << " " << p.second.first << " " << p.second.second << endl;
    }
}