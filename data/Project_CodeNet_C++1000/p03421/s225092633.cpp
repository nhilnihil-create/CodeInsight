#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=3E5+77;
typedef long long LL; 

LL N,A,B,V[maxn];
int cv=0,idx[maxn],ans[maxn];

bool cmp(int a,int b){ 
        return V[a]<V[b];
}

int main(){
        cin>>N>>A>>B;
        if(A+B>N+1 || A*B<N){
                printf("-1\n");
                return 0;
        }   

        N-=A;
        for(LL i=B;i<=B*A;i+=B){
                V[cv++]=i;
                for(LL j=1;N && j<B;++j){
                        --N;
                        V[cv++]=i-j;
                }   
        }   

        for(int i=0;i<cv;++i) idx[i]=i;
        sort(idx,idx+cv,cmp);
        for(int i=0;i<cv;++i) ans[idx[i]]=i+1;
        printf("%d",ans[0]);
        for(int i=1;i<cv;++i) printf(" %d",ans[i]);
        printf("\n");
 }
