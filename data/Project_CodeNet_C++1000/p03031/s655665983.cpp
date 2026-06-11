#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> k(11);
    vector<vector<int>> s(11,vector<int>(11));
    for(int i=0;i<M;i++){
        cin >> k[i];
        for(int j=0;j<k[i];j++){
            cin >> s[i][j];
        }
    }
    vector<int> p(M);
    for(int i=0;i<M;i++){
        cin >> p[i];
    }
    //スイッチの状態に対し、ビット全探索
    int ans=0;
    for(int i=0;i<(1<<N);i++){
        //各電球に対し検証
        int flag=0;
        for(int j=0;j<M;j++){
            int count=0;
            for(int l=0;l<k[j];l++){
                if(i>>(s[j][l]-1)&1){
                    count++;
                }    
            }
            if(count%2==p[j]) flag++;
        }
        if(flag==M) ans++;
    }
    cout << ans << endl;
    return 0;

}