#include"bits/stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void sort2array(double *a,long *b,long n){
    for(int i=0;i<n;i++){
        b[i]=i;
    }
    sort(b,b+n,[a](long i,long j)->bool {return a[i]<a[j];} );
}
//bを何回足せばaを超えるか
int wtover(int a,int b){
    if(a%b>0)return (a/b)+1;
    else return a/b;
}
const int INF=100000001,ID_MAX=20;
int bi_e[ID_MAX]={0};
//2進数表示したときの最高桁
int bi_max(long n){
    int m=0;
    for(m;pow(2,m)<=n;m++);m=m-1;
    return m;
}
//bi_eに二進数表示したやつを代入
void bi_exs(long n){
    rep(i,ID_MAX){
        bi_e[i]=0;
    }
    if(n<pow(2,ID_MAX)){
        int m=bi_max(n);
        long l;
        for(m;m>-1;m--){
            l=pow(2,m);
            bi_e[m]=n/l;
            n=n%l;
        }
    }
}

long int x,y;

int solve(){
    long int count=1,m=x;
    while(m*2<=y){
        m=m*2;
        count++;
    }
    return count;
}

int main(){
    int i;
    //入力
    cin>>x>>y;
    //処理
    int ans=solve();
    //出力
    cout<<ans<<endl;
}