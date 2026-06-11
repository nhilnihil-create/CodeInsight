#include <cmath>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    int Q;
    long long max=101010;
    vector<long long> is_prime(max,1);
    is_prime[0]=0;is_prime[1]=0;

    for(long long i =2;i<max;i++){
        if(!is_prime[i]) continue;
        for(int j=i*2;j<max;j+=i)is_prime[j]=0;
    }
   
    vector<long long> like(max,0);
    for(long long i=0;i<max;i++){
        if(i%2==0) continue;
        if(is_prime[i] && is_prime[(i+1)/2])like[i]=1;
    }

    vector<long long> sum(max+1,0);
    for(long long i=0;i<max;i++){
        sum[i+1]=sum[i]+like[i];
    }

    cin>>Q;
    for(long long i =0;i<Q;i++){
        long long l,r;
        cin>>l>>r;
        ++r;
        cout<<sum[r]-sum[l]<<endl;
    }
}