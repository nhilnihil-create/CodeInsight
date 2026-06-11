#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>m(n);
    rep(i,n)cin>>m[i];
    int under=0;
    rep(i,n)under+=m[i];
    x-=under;
    sort(m.begin(),m.end());
    int cnt=0;
    int now=0;
    rep(i,100000){
        
        now+=m[0];

        if(now<=x)cnt+=1;
        else break;
    }
    
    cout<<cnt+n<<endl;
}