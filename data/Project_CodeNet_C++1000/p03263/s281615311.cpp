#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    int a[h][w];
    int flag[h][w];
    for(int i = 0;  i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
            flag[i][j] = 0;
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<pair<int, int> > ans_1;
    vector<pair<int, int> > ans_2;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] % 2 == 1){
                int che = 0;
                for(int k = 0; k < 4; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 0 && x < h && y >= 0 && y < w){
                        if(a[x][y] % 2 == 1){
                            a[i][j]--;
                            a[x][y]++;
                            ans_1.push_back(make_pair(i, j));
                            ans_2.push_back(make_pair(x, y));
                            che = 1;
                            break;
                        }
                    }
                }

                if(che == 0){
                    for(int k = 0; k < 4; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(x >= 0 && x < h && y >= 0 && y < w){
                            if(flag[x][y] == 0){
                                a[i][j]--;
                                a[x][y]++;
                                ans_1.push_back(make_pair(i, j));
                                ans_2.push_back(make_pair(x, y));
                                break;
                            }
                        }
                    }
                }
            }
            flag[i][j] = 1;
        }
    }

    cout << ans_1.size() << endl;
    for(int i = 0; i < ans_1.size(); i++){
        cout << ans_1[i].first + 1 << " " << ans_1[i].second + 1 << " " << ans_2[i].first + 1 << " " << ans_2[i].second + 1 << endl;
    }
}