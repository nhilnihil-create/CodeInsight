#include <bits/stdc++.h>
using namespace std;

int d[50][50];
int o[3][50]; //色別の出現回数

int main(){
    int n,c; cin >> n >> c;
    for(int i=1;i<=c;i++){
        for(int j=1;j<=c;j++){
            cin >> d[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int col; cin >> col;
            o[(i+j)%3][col]++;
        }
    }
    int ans=1e9;
    for(int c1=1;c1<=c;c1++){
        for(int c2=1;c2<=c;c2++){
            for(int c3=1;c3<=c;c3++){
                if(c1==c2 || c2==c3 || c3==c1) continue;
                int cost=0;
                for(int i=1;i<=c;i++){
                    cost+=o[0][i]*d[i][c1];
                    cost+=o[1][i]*d[i][c2];
                    cost+=o[2][i]*d[i][c3];
                }
                ans=min(ans,cost);
            }
        } 
    }

    cout << ans << endl;    
}