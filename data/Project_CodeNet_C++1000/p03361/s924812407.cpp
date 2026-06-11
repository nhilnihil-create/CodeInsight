#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int>> color(h, vector<int>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char c;
            cin >> c;
            if(c == '#') color.at(i).at(j) = 1;
            else color.at(i).at(j) = 0;
        }
    }
    bool possible = true;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(color.at(i).at(j) == 0) continue;
            int cnt=0;
            for(int k=-1; k<=1; k++){
                for(int l=-1; l<=1; l++){
                    if(0<=i+k && i+k<h){
                        if(0<=j+l && j+l<w){
                            if(abs(k)+abs(l) == 1){
                                cnt+=color.at(i+k).at(j+l);
                            }
                        }
                    }
                }
            }
            if(cnt==0){
                possible = false;
            }
            //cout << cnt;
        }
        //cout << endl;
    }
    if(possible) cout << "Yes" << endl;
    else cout << "No" << endl;

}