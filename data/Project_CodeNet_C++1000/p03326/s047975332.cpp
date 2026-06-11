#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<numeric>
using namespace std;
int main(){
    int N,M;cin>>N>>M;
    long x[N],y[N],z[N],ans=0L;
    vector<long>v(N);
    for(int i=0;i<N;i++)cin>>x[i]>>y[i]>>z[i];
    for(int bit=0;bit<8;bit++){
        bitset<3>b(bit);
        for(int i=0;i<N;i++)v[i]=x[i]*(b[0]?-1:1)+y[i]*(b[1]?-1:1)+z[i]*(b[2]?-1:1);
        sort(v.begin(),v.end(),greater<long>());
        ans=max(ans,accumulate(v.begin(),v.begin()+M,0L));
    }
    cout<<ans<<endl;
    return 0;
}