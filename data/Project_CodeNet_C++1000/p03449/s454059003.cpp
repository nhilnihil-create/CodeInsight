#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(n) begin(n),end(n)

int main(){
    int n;
    cin>>n;

    vector<int> a(n),b(n);
    REP(i,n){
        cin>>a[i];
    }
    REP(i,n){
        cin>>b[i];
    }

    int sum=0,max=0;
    REP(i,n){
        sum=0;
        REP(j,n){
            if(j<i){
                sum+=a[j];
            }else if(j==i){
                sum+=(a[j]+b[j]);
            }else{
                sum+=b[j];
            }
        }
        if(sum>max){
            max=sum;
        }
    }

    cout<<max<<endl;
}
