#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main() {
    int n;
    cin>>n;
   

    int T;
    cin>>T;
    int A;
    cin>>A;
  
    vector<int> h(n);
    rep(i,n)cin>>h[i];
  
    vector<double> t(n);
    rep(i,n)t[i]=T-h[i]*0.006;
   
    vector<double> a(n);
    rep(i, n)a[i]=abs(A-t[i]);
    
    double min=a[0];
    int index=0;
    
    rep(i,n){
        if(a[i]<=min){
            min=a[i];
            index=i+1;
        }
    }
    
    cout<<index<<endl;
    
//    3
//    21 -11
//    81234 94124 52141

    
    return 0;
    }