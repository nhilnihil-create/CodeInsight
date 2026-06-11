#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt,ans,a,b,c,d[ohara],tmp,tmpp,m,h,w,x[ohara],y[ohara],sum,pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz");
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int check(){
    int ret=1;
    ll dis=abs(x[n-1])+abs(y[n-1]);
    rep(i,n){
        if((abs(x[i])+abs(y[i]))%2!=dis%2)ret=-1;
    }
    return ret;
}

void solve1(){
        Cout(34);
        cnt=1;
        d[0]=1;
        d[1]=1;
        rep(i,32){
            d[i+2]=cnt;
            cnt*=2;
        }
        reverse(d,d+34);
        rep(i,34){
            if(i==33)Cout(d[i]);
            else cout<<d[i]<<" ";
        }
        rep(i,n){
            string s;
            tmp=0;
            rrep(j,tmp,34){
                if(abs(x[i])<abs(y[i])){
                    if(y[i]<0){
                        y[i]+=d[j];
                        s+='D';
                    }
                    else{
                        y[i]-=d[j];
                        s+='U';
                    }
                }
                else{
                    if(x[i]<0){
                        x[i]+=d[j];
                        s+='L';
                    }
                    else{
                        x[i]-=d[j];
                        s+='R';
                    }
                }
            }
            Cout(s);
            //cout<<x[i]<<" "<<y[i]<<"\n";
        }
        return ;
}

void solve2(){
        Cout(35);
        d[0]=1;
        d[1]=1;
        d[2]=1;
        cnt=1;
        rep(i,32){
            d[i+3]=cnt;
            cnt*=2;
        }
        reverse(d,d+35);
        rep(i,35){
            if(i==34)Cout(d[i]);
            else cout<<d[i]<<" ";
        }
        rep(i,n){
            string s;
            tmp=0;
            rrep(j,tmp,35){
                if(abs(x[i])<=abs(y[i])){
                    if(y[i]<0){
                        y[i]+=d[j];
                        s+='D';
                    }
                    else{
                        y[i]-=d[j];
                        s+='U';
                    }
                }
                else{
                    if(x[i]<0){
                        x[i]+=d[j];
                        s+='L';
                    }
                    else{
                        x[i]-=d[j];
                        s+='R';
                    }
                }
            }
            Cout(s);
            //cout<<x[i]<<" "<<y[i]<<"\n";
        }
        return ;
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    rep(i,n)cin>>x[i]>>y[i];
    if(check()==-1)Cout(-1);
    else{
        if((abs(x[0])+abs(y[0]))%2==1)solve1();
        else solve2();
    }
    return 0;
}
