#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>

 
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define LLIandI pair<long long int , int>
#define ll long long
int main(void){
    int N;
    long long int C;
    scanf("%d %lld",&N,&C);
    long long int x[100004];
    long long int v[100004];
    long long int v_inc[100004];
    long long int v_inc_max[100004];
    long long int v_dec[100004];
    long long int v_dec_max[100004];
    rep(i,N){
        scanf("%lld %lld",&x[i],&v[i]);
        i==0 ? (v_inc[i]=v[i]-x[i]) : (v_inc[i]=v_inc[i-1]+v[i]-(x[i]-x[i-1]) );
        i==0 ? (v_inc_max[i]= v_inc[i]) : (v_inc_max[i]=max(v_inc[i],v_inc_max[i-1]));
    }
    rep(i,N){
        int j=N-1-i;
        i==0?(v_dec[j]=v[j]-(C-x[j])) : (v_dec[j]=v_dec[j+1]+v[j]-(x[j+1]-x[j]) );
        i==0?(v_dec_max[j]= v_dec[j]) : (v_dec_max[j]=max(v_dec[j],v_dec_max[j+1]));
    }
    
    long long int ans=0;//動かないという選択肢
    rep(i,N){
        if(i==N-1 || v_dec_max[i+1]<=x[i]){ans=max(ans,v_inc[i]);continue;}//方向転換しないのがベスト
        else{ans=max(ans,v_inc[i]-x[i]+v_dec_max[i+1]);continue;}//方向転換するのがベスト
    }
    //from decriment
    rep(i,N){
        int j=N-1-i;
        if(j==0||v_inc_max[j-1]<=C-x[j]){ans=max(ans,v_dec[j]);continue;}
        else{ans=max(ans,v_dec[j]-(C-x[j])+v_inc_max[j-1]);continue;}//方向転換するのがベスト
    }
    printf("%lld\n",ans);
}
