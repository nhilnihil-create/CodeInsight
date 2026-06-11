#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;

    long long int lis[100][2];
    long long int ans=4000000000000000001;
    for(int i=0;i<N;i++)cin>>lis[i][0]>>lis[i][1];
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            for(int k=j;k<N;k++){
                for(int l=k;l<N;l++){
                    long long int xmax=-2000000000000000000,ymax=-2000000000000000000,xmin=2000000000000000000,ymin=2000000000000000000;
                    xmax=max(max(lis[i][0],lis[j][0]),max(lis[k][0],lis[l][0]));
                    ymax=max(max(lis[i][1],lis[j][1]),max(lis[k][1],lis[l][1]));
                    xmin=min(min(lis[i][0],lis[j][0]),min(lis[k][0],lis[l][0]));
                    ymin=min(min(lis[i][1],lis[j][1]),min(lis[k][1],lis[l][1]));
                    int cou=0;
                    for(int m=0;m<N;m++){
                        if(xmin<=lis[m][0]&&lis[m][0]<=xmax){
                            if(ymin<=lis[m][1]&&lis[m][1]<=ymax){
                                cou++;
                            }
                        }
                    }
                    if(K<=cou){
                        ans=min(ans,(xmax-xmin)*(ymax-ymin));
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
