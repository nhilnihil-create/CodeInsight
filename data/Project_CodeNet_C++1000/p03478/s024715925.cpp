#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int sum=0;
    for(int i=1;i<=n;i++){
        int tmp=i;
        int num=0;
        while(tmp!=0){
            num+=tmp%10;
            tmp/=10;
        }
        if(num>=a && num<=b) sum+=i;
    }
    cout<<sum<<"\n";
    return 0;
}