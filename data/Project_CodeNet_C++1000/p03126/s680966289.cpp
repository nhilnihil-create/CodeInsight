#include <iostream>
using namespace std;

int main(){
    int M,N,K,i,j,k,output,man_like,all_men_like;
    output=0;
    cin>>N>>M;
    int list[N][M];
    for (i=0;i<N;i++){
        for (j=0;j<M;j++){
            list[i][j]=0;
        }
    }
    for (i=0;i<N;i++){
        cin>>K;
        for (j=0;j<K;j++){
            cin>>list[i][j];
        }
    }
    
    for (i=1;i<=M;i++){
        all_men_like = 1;
        for (j=0;j<N;j++){
            man_like=0;
            for (k=0;k<M;k++){
                if (i == list[j][k]){
                    man_like=1;
                }
            }
            if (man_like==0){
                all_men_like=0;
            }
        }
        output+=all_men_like;
    }
    cout<<output<<endl;
}