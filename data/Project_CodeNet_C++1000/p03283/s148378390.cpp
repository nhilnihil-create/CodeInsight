#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,M,Q;
    cin >> N >> M >> Q;

    vector<vector<int>> sum(N+1,vector<int> (N+1,0)),sumL(N+1,vector<int> (N+1,0));

    for(int i=0;i<M;i++){
        int L,R;
        cin >> L >> R;
        sum[L][R]++;
    }

    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(j==0){
                sumL[i][j] = sum[i][j];
            }else{
                sumL[i][j] = sumL[i][j-1] + sum[i][j];
            } 
        }
    }

    for(int i=0;i<Q;i++){
        int p,q,ans=0;
        cin >> p >> q;
        for(int j=p;j<=q;j++){
            ans += sumL[j][q] - sumL[j][p-1];
        }

        cout << ans << endl;
    }
}