#include<iostream>
#include<algorithm>
using namespace std;
long long N,A,B,ans;
int main(void){
    cin>>N;
    long long cuisine[N];
    for(int i=0;i<N;i++){cin>>A>>B;cuisine[i]=A+B;ans+=A;}
    sort(cuisine,cuisine+N,std::greater<long long>());
    for(int i=1;i<N;i+=2){ans-=cuisine[i];}
    cout<<ans<<endl;
    return 0;
}