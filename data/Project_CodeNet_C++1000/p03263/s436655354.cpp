#include <bits/stdc++.h>

using namespace std;

int main(){
    int H,W,ans=0;
    cin >> H >> W;
    int coins[H][W];
    vector<pair<int,int>> from,to;
    pair<int,int> P;

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> coins[i][j];
        }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W-1;j++){
            if(coins[i][j]%2==1){
                if(j!=W-1){
                    coins[i][j]--;
                    coins[i][j+1]++;
                    P.first = i;
                    P.second = j;
                    from.push_back(P);
                    P.second = j+1;
                    to.push_back(P);
                    ans++;
                }
            }
        }
    }

    for(int i=0;i<H;i++){
        if(coins[i][W-1]%2==1){
            if(i!=H-1){
                coins[i][W-1]--;
                coins[i+1][W-1]++;
                P.first = i;
                P.second = W-1;
                from.push_back(P);
                P.first = i+1;
                to.push_back(P);
                ans++;
            }
        }
    }

    cout << ans << endl;

    for(int i=0;i<from.size();i++){
        cout << from[i].first+1 << " " << from[i].second+1 << " " << to[i].first+1 << " " << to[i].second+1 << endl;
    }

}