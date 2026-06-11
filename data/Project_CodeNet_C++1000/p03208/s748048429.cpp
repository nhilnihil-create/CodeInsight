#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(n) begin(n),end(n)

int main(){
    int n,k;
    cin>>n>>k;

    vector<int> h(n);
    REP(i,n){
        cin>>h[i];
    }
    sort(ALL(h));

    int d,d_min;
    REP(i,n-k+1){
        d=h[i+k-1]-h[i];
        if(i==0){
            d_min=d;
        }else{
            if(d<d_min){
                d_min=d;
            }
        }
    }

    cout<<d_min<<endl;
}