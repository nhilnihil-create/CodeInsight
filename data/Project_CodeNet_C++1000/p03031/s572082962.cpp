#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    
    int N,M;
    cin >> N >> M;
    vector<vector<int>> S(M,vector<int>(N+1,0));
    
    for(int i=0;i<M;i++){
        int j;
        cin >> j;
        for(int k=0;k<j;k++)cin >> S[i][k];
    }
    vector<int> P(M,0);
    
    for(int i=0;i<M;i++)cin >> P[i];
    
    int count0=0;
    
    for(int i=0;i<1<<N;i++){
        
        int count1=0;
        for(int l=0;l<M;l++){
            int count2=0;
            for(int j=0;S[l][j]!=0;j++){
                count2+=((1<<(S[l][j]-1)&i)!=0);
            }
            if(count2%2!=P[l])break;
            count1+=(count2%2==P[l]);
        }
        count0+=(count1==M);
    }
    cout << count0 << endl;
    
}
