#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
    int h, w, in;
    cin >> h >> w;
    vector<vector<int>> a(0, vector<int>(2));
    vector<vector<int>> map(h, vector<int>(w));
    int sum2 = 0;
    rep(i, h){
        rep(j, w){
            cin >> map.at(i).at(j);
            if(map.at(i).at(j)%2 == 1) sum2++;
        }
    }
    int sum = 0;
    int p = 0;
    rep(i, h){
        if(i%2 == 0){
            for(int j=0; j<w; j++){
                if(map.at(i).at(j)%2 == 1){
                    p++;
                }
                if(p%2 == 1 && p != sum2){
                    sum++;
                }
            }
        }else{
            for(int j=w-1; j>=0; j--){
                if(map.at(i).at(j)%2 == 1){
                    p++;
                }
                if(p%2 == 1 && p != sum2){
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;
    int cou = 0;
    int p0 = 0;
    rep(i, h){
        if(i%2 == 0){
            for(int j=0; j<w; j++){
                if(map.at(i).at(j)%2 == 1){
                    p0++;
                }
                if(p0%2 == 1 && p0 != p){
                    if(j != w-1){
                        cout << i+1 << ' ' << j+1 << ' ' << i+1 << ' ' << j+1+1 << endl;
                    }else{
                        cout << i+1 << ' ' << j+1 << ' ' << i+1+1 << ' ' << j+1 << endl;
                    }
                }
            }
        }else{
            for(int j=w-1; j>=0; j--){
                if(map.at(i).at(j)%2 == 1){
                    p0++;
                }
                if(p0%2 == 1 && p0 != p){
                    if(j != 0){
                        cout << i+1 << ' ' << j+1 << ' ' << i+1 << ' ' << j-1+1 << endl;
                    }else{
                        cout << i+1 << ' ' << j+1 << ' ' << i+1+1 << ' ' << j+1 << endl;
                    }
                }
            }
        }
    }
    return 0;
}