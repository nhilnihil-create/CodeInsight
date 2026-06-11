#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    string s;
    cin>>s;
    long long ans=0,si=s.size();
    f2(i,s.size()-1,-1){
        if(s[i]=='B'){
            ans+=si-i-1;
            si--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
