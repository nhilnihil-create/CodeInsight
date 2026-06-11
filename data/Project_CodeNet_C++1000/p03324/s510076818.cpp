#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int d,n;
    cin>>d>>n;
    if(n==100) n++;
    if(d==0) cout<<n<<"\n";
    else if(d==1) cout<<100*n<<"\n";
    else if(d==2) cout<<10000*n<<"\n";
    return 0;
}