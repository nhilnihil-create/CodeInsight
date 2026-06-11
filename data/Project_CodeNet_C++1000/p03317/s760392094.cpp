#include<bits/stdc++.h>

using namespace std;

int main()
{
    int K,N,ans=0,sum=0;
    cin>>K>>N;
    sum=N,ans=1;
    while(sum<K) {sum+=N-1; ans++;}
    cout<<ans<<endl;
    return 0;
}
