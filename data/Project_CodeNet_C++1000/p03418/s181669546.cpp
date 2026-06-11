#include<iostream>
using namespace std;
int main(){
    long long n,k,ans=0LL;
    cin>>n>>k;
    for(long long b=k+1LL;b<=n;b++)ans+=(n/b)*(b-k)+max(n%b-k+(k!=0LL),0LL);
    cout<<ans<<endl;
    return 0;
}