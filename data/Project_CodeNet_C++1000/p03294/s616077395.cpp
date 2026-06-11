#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(n) begin(n),end(n)

int main(){
    long long n;
    cin>>n;

    vector<long long> a(n);
    long long sum=0;
    REP(i,n){
        cin>>a[i];
        sum+=a[i]-1;
    }

    cout<<sum<<endl;
}