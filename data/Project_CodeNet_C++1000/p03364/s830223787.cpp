#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2001,INF=1<<30;
 
int main(){
    
    int N;cin>>N;
    vector<vector<char>> S(N,vector<char>(N));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>S[i][j];
        }
    }

    int cnt=0;

    for(int k=0;k<N;k++){
        bool flag=true;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int x=(i+k)%N,y=(j+k)%N;
                if(S[x][j]!=S[y][i]) flag=false;
            }
        }
        if(flag) cnt++;
    }

    cout<<cnt*N<<endl;
}
