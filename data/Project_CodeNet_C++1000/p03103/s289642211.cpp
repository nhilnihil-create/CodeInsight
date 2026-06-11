#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin>>n>>m;
    vector<map<int,int>>line(n);
    rep(i,n){
        ll a,b;
        cin>>a>>b;
        line[i][0]=a;
        line[i][1]=b;
    }
    sort(line.begin(),line.end());
    ll total=0;
    
    rep(i,n){
        rep(j,line[i][1]){
            m-=1;
            total+=line[i][0];
            if(m==0) break;
        }
        if(m==0) break;
        

    }
   
    cout<<total<<endl;
}

   