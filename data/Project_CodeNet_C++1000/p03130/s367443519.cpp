#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;

int d[4][4];

int main(){

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            d[i][j] = INF;
        }
    }
    
    for(int i=0; i<3; i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        d[a][b] = 1;
        d[b][a] = 1;
    }

    for(int k=0; k<4; k++){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    bool flag = false;

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(d[i][j] == 3){
                flag = true;
            }
        }
    }

    cout<<(flag ? "YES" : "NO")<<endl;

    return 0;
}