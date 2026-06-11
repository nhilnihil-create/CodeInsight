#include <bits/stdc++.h>
#define inf 2333333333333333
#define N 1000010
#define p(a) putchar(a)
#define For(i,a,b) for(int i=a;i<=b;++i)

using namespace std;
int n,m;
typedef pair<int,int>P;
queue<P>q;
void in(int &x){
    int y=1;char c=getchar();x=0;
    while(c<'0'||c>'9'){if(c=='-')y=-1;c=getchar();}
    while(c<='9'&&c>='0'){ x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    x*=y;
}
void o(int x){
    if(x<0){p('-');x=-x;}
    if(x>9)o(x/10);
    p(x%10+'0');
}

signed main(){
    in(n);
    For(i,1,n){
        For(j,i+1,n){
            if(j!=n-i+(n%2==0?1:0)){
                m++;
                q.push(P(i,j));
            }
        }
    }
    o(m);p('\n');
    while(!q.empty()){
        auto k=q.front();q.pop();
        o(k.first);p(' ');o(k.second);p('\n');
    }
    return 0;
}