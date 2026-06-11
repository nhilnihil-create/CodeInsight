#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;
    int lis[100];
    for(int i=0;i<N;i++){
        cin>>lis[i];
    }
    long long int ans=-5000000000000;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(N<i+j||K<i+j)continue;
            int karilis[100]={0};
            int karinum=0;
            for(int k=0;k<i;k++){
                karilis[karinum]=lis[k];
                karinum++;
            }
            for(int k=0;k<j;k++){
                karilis[karinum]=lis[N-1-k];
                karinum++;
            }
            sort(karilis,karilis+karinum);
            if(i==2&&j==1){
                for(int k=0;k<karinum;k++){
                    //printf("[%d]",karilis[k]);
                }
                //puts("");
            }
            int kokokara;
            for(int k=0;i+j+k<=K&&k<karinum;k++){
                kokokara=k;
                if(0<=karilis[k])break;
            }
            long long int karians=0;
            for(int k=kokokara;k<karinum;k++){
                karians+=karilis[k];
            }
            //printf("[%d][%d][%lld]\n",i,j,karians);
            ans=max(ans,karians);
        }
    }
    cout<<ans<<endl;
    return 0;
}
