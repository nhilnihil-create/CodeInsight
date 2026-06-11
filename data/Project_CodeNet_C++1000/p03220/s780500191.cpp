#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N,T,A;
   cin>>N>>T>>A;
   map<double,int> data;
   int H;
   double m=1000;
   rep(i,N){
        cin>>H;
        data[abs(A-T+0.006*H)]=i+1;
        m=min(m,abs(A-T+0.006*H));
   
    }
    cout<<data[m]<<endl;
}