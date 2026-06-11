#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N,M;
int swi[10][10];
int tuku[10];
int now[10];
int ans;
void func(int s){
    if(s==N){
        int flg=1;
        for(int i=0;i<M;i++){
            int cou=0;
            for(int j=0;j<N;j++){
                if(swi[i][j]==1&&now[j]==1)cou++;
            }
            if(cou%2!=tuku[i]){
                flg=0;
            }
        }
        ans+=flg;
        return;
        /*
        int flg=1;
        for(int i=0;i<M;i++)
        if(nowsum[i]%2!=tuku[i])flg=0;
        ans+=flg;
        return;
        */
    }




    func(s+1);


    now[s]++;
    func(s+1);
    now[s]--;

}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int K;
        cin>>K;
        for(int j=0;j<K;j++){
            int a;
            cin>>a;
            swi[i][a-1]=1;
        }
    }
    for(int i=0;i<M;i++)cin>>tuku[i];
    func(0);
    cout<<ans<<endl;
    return 0;
}
