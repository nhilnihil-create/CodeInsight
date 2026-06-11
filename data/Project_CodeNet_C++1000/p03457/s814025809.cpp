#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(n) begin(n),end(n)

int main(){
    int n;
    cin>>n;

    vector<int> t(n),x(n),y(n);
    REP(i,n){
        cin>>t[i]>>x[i]>>y[i];
    }

    bool judge=true;

    if(!(t[0]%2==(x[0]+y[0])%2 && t[0]>=x[0]+y[0])){
        judge=false;
    }

    int i=1;
    while(judge && i<n){
        if(!((t[i]-t[i-1])%2==(abs(x[i]-x[i-1])+abs(y[i]-y[i-1]))%2 && (t[i]-t[i-1])>=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]))){
            judge=false;             
        }
        i++;
    }
    
    cout<<(judge ? "Yes" : "No")<<endl;
}