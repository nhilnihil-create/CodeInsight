#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int (i)=(l);(i)<(r);i++)
#define erep(i,l,r) for(int (i)=(l);(i)<=(r);i++)
#define MOD 1000000007
using namespace std;
int main(){
    int n,ans=0,a=0,b=0,c=0;
    cin>>n;
    rep(i,0,n){
        string s;
        cin>>s;
        rep(j,0,(int)s.length()-1) if(s[j]=='A'&&s[j+1]=='B')ans++;
        if(s[0]=='B'){
            if(s[s.length()-1]=='A')c++;
            else b++;
        }
        else if(s[s.length()-1]=='A')a++;
    }
    if(a+b==0&&c>0)c--;
    cout<<ans+c+min(a,b)<<endl;
}