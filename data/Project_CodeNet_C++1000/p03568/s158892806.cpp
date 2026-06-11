#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    int sum1=pow(3,n);
    int sum2=1;
    rep(i,n){
        cin>>a[i];
        if(a[i]%2==0)sum2*=2;
    }
    cout<<sum1-sum2<<endl;
}
