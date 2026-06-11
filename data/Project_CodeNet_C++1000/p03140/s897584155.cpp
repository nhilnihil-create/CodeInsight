#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;


int main(){
int N;
cin>>N;
string a,b,c;
cin>>a>>b>>c;
long long ans=0;
rep(i,N){
    char d=a[i];
    char e=b[i];
    char f=c[i];
    int dcnt=1;
    int ecnt=1;
    int fcnt=1;
    if(d==b[i]){
        dcnt++;
    }
    if(d==c[i]){
        dcnt++;
    }
    if(e==a[i]){
        ecnt++;
    }
    if(e==c[i]){
        ecnt++;
    }
    if(f==a[i]){
        fcnt++;
    }
    if(f==b[i]){
        fcnt++;
    }
    int p=max(fcnt,dcnt);
    ans+=3-max(p,ecnt);
}
cout<<ans<<endl;
 return 0;
}
/*
4
west
east
wait

3

9
different
different
different

0

7
zenkoku
touitsu
program

13
*/