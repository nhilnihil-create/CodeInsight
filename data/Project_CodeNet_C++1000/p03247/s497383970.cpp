#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int l[N],r[N];
int ans[N],n,c;
string s;
int main()
{
    cin>>n;c=0;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
        if((l[i]+r[i])%2==0)c--;
        else c++;
    }
    if(abs(c)!=n){
        puts("-1");return 0;
    }
    int m=31+(c<0);
    for(int i=0;i<=30;i++){
        ans[i]=(1<<i);
    }
    if(c<0){
        ans[31]=1;
    }
    cout<<m<<endl;
    for(int i=0;i<m;i++){
        cout<<ans[i];
        if(i!=m-1)cout<<" ";else cout<<endl;
    }
    for(int i=1;i<=n;i++){
        int x=l[i],y=r[i];s.clear();
        if(c<0)x++,s[31]='L';int f=0;
        for(int j=30;j>=0;j--){
            if(abs(x)<abs(y))swap(x,y),f^=1;
            if(x<0)x+=(1<<j),s[j]=(f?'D':'L');
            else x-=(1<<j),s[j]=(f?'U':'R');
        }
        for(int j=0;s[j];j++)cout<<s[j];
        cout<<endl;
    }
}
