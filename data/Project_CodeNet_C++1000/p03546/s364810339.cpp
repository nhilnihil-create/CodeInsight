#include <bits/stdc++.h>
using namespace std;

int H, W;
int c[10][10];
int A[200][200];
int cost[10][10];
int const INF = 100100100;
typedef pair<int, int> P;

int main(void){
    cin >> H >> W;
    
    for (int i=0; i<10; i++) for (int j=0; j<10; j++) cin >> c[i][j];
    for (int i=0; i<H; i++) for (int j=0; j<W; j++) cin >> A[i][j];
    
    for (int i=0; i<10; i++) fill(cost[i], cost[i] + 10, INF);
    
    for (int s=0; s<10; s++){
        cost[s][s] = 0;
        priority_queue<P, vector<P>, greater<P>> que;
        que.push(pair(s, 0));
        
        while(!que.empty()){
            P p=que.top(); que.pop();
            
            if(cost[s][p.first] < p.second) continue; 
            
            for (int i=0; i<10; i++){
                if(cost[s][p.first] + c[p.first][i] < cost[s][i]){
                    cost[s][i] = cost[s][p.first] + c[p.first][i];
                    que.push(P(i, cost[s][i]));
                }
            }
        }
    }
    
    int ans = 0;
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            if(A[i][j] != -1){
                ans += cost[A[i][j]][1];
            }
        }
    }
    cout << ans << endl;
}
