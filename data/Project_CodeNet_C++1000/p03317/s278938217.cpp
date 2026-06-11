#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(n) begin(n),end(n)

int main(){
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    REP(i,n){
        cin>>a[i];
    }

    if((n-1)%(k-1)==0){
        cout<<(n-1)/(k-1)<<endl;
    }else{
        cout<<(n-1)/(k-1)+1<<endl;
    }    
}