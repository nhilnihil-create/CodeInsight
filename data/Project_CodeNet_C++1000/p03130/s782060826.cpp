#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int path[4][4]= {0};
    for(int i = 0; i < 3; i++){
        int a,b;
        cin >> a >> b;
        path[a - 1][b - 1] = path[b - 1][a - 1] = 1;
    }
        for(int i = 0; i < 4; i++){
            int cnt = 0;
            for(int j = 0; j < 4; j++){
                if(path[i][j] == 1)
                    cnt++;
            }
            if(cnt == 3 || cnt == 0){
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
    }
