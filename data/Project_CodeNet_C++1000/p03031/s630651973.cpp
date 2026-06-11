#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N,M;
    cin>>N>>M;
    int A[M][10];
    rep(i,M)rep(j,N)A[i][j]=-1;
    rep(i,M){
        int k;
        cin>>k;
        rep(j,k){
            int s;
            cin>>s;
            A[i][j]=s;
        }
    }
    int p[M];
    rep(i,M){
        int q;
        cin>>q;
        p[i]=q;
    }
    int ans=0;
    for(int bit=0; bit<(1<<N); ++bit){
        int allon=0;
        rep(i, M){
            int on=0;
            rep(j,10){
                if(A[i][j]==-1)break;
                else if(bit&(1<<(A[i][j]-1)))on++;
            }    
            if(on%2==p[i])allon++;
        }
        if(allon==M)ans++;
    }
    cout<<ans<<endl;
    return 0;
}