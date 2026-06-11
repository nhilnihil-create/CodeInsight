#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved
int main(){
    int n,c;
    cin>>n>>c;

    int t_table[100010][31]={};
    rep(i,n){
        int s,t,c;
        cin>>s>>t>>c;
        t_table[s][c]++;
        t_table[t+1][c]--;
    }

    rep2(i,c){
        rep2(k,100000){
            t_table[k][i]+=t_table[k-1][i];
        }
    }
    /*
    rep2(i,c){
        rep2(k,50){
            cout<<t_table[k][i]<<" ";
        }
        cout<<endl;
    }*/
    long long ans=-1;
    rep2(k,100000){
        long long tmp=0;
        rep2(i,c){
            if(t_table[k][i])tmp++;
        }
        ans=max(tmp,ans);
    }
    cout<<ans<<endl;
    return 0;

}
/*

3 2
1 7 2
7 8 1
8 12 1

2

3 4
1 3 2
3 4 4
1 4 3

3


9 4
56 60 4
33 37 2
89 90 3
32 43 1
67 68 3
49 51 3
31 32 3
70 71 1
11 12 3

2
*/
