#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1001];
long long b[1001];
char ans[1001][50];
long long dy[4]={1,0,-1,0};
long long dx[4]={0,1,0,-1};
char c[5]="DLUR";
int q;
long long abs2(long long k){
    return k>0 ? k:-k;
}
int isok(long long x,long long y,int lev){
    if(abs2(x)+abs2(y)<=((long long)1<<lev) )return 1;
    return 0;
}
void f(int lev,long long x,long long y,int k){

   /// cout<<lev<<" "<<x<<" "<<y<<endl;
    if(lev==-1){
        for(int i=0 ; i<4 ; i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx==0 && yy==0){
                ans[k][lev+1]=c[i];
                return;
            }
        }
        return;
    }
    long long l=1;
    long long t=(l<<lev);
    for(int i=0 ; i<4 ; i++){
        long long xx=x+t*dx[i];
        long long yy=y+t*dy[i];
        if(isok(xx,yy,lev)){
            ans[k][lev+1-q]=c[i];
            f(lev-1,xx,yy,k);
            return;
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int i;
    cin>>n;
    for(i=1 ; i<=n ; i++){
        cin>>a[i]>>b[i];
        if(abs2(a[i]+b[i])%2!=abs2(a[1]+b[1])%2){
            cout<<-1;
            return 0;
        }
        q=abs2(a[i]+b[i])%2;
        f(30,a[i],b[i],i);
    }
    cout<<(32-q)<<endl;
    if(q){
        for(i=0 ; i<=30 ; i++){
            cout<<(1<<i)<<" ";
        }
    }
    else{
        cout<<1<<" ";
        for(i=0 ; i<=30 ; i++){
            cout<<(1<<i)<<" ";
        }
    }
    cout<<"\n";
    for(i=1 ; i<=n ; i++){
        cout<<(ans[i])<<"\n";
    }
    return 0;

}
