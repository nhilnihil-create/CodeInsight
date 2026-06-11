#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=300005;
 
inline int read(){
    int x=0; char ch=getchar();
    for(;!isdigit(ch);ch=getchar());
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
    return x;
}
 
void W(int x){ if(x>=10) W(x/10); putchar(x%10+'0');}
 
int n,a[N],c[N],l,ans[N];
 
inline void update(int pos,int val){
    if(val>a[pos]) c[pos]=a[pos],a[pos]=val;
    else if(val>c[pos]) c[pos]=val;
}
 
inline void solve(){
    for(int i=0,to;i<l;i++)
        for(int j=0;j<n;j++) if(!((1<<i)&j)){
            to=j|(1<<i);
             
            update(to,a[j]);
            update(to,c[j]);
        }
}
 
int main(){
    scanf("%d",&n),l=n,n=1<<n;
    for(int i=0;i<n;i++) a[i]=read(),c[i]=0;
     
    solve();
     
    for(int i=1;i<n;i++){
        ans[i]=max(ans[i-1],a[i]+c[i]);
        W(ans[i]),puts("");
    }
     
    return 0;
}