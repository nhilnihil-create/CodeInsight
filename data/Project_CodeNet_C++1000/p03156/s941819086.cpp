#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
const int INF=1e9;
const ll LINF=(ll)1e18;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int c1=0,c2=0,c3=0;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        if(p<=a)c1++;
        else if(b+1<=p)c3++;
        else c2++;
    }
    cout<<min({c1,c2,c3})<<endl;
}
