#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i,s,e) for(int i=s;i<e;i++)
#define endl '\n'
int main(){
    int n,a,b;cin>>n>>a>>b;
    int res=0;
    for(int i=1;i<=n;i++){
        int sum=0;
        int tmp=i;
        while (tmp>0)
        {
            sum+=tmp%10;
            tmp/=10;
        }
        if(a<=sum && sum<=b)res+=i;
    }
    cout<<res<<endl;
}