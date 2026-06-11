#include<bits/stdc++.h>

using namespace std;


map<long long, long long> prime_factors(long long P,long long N) {
    map<long long, long long> res;
    if(P == 1) { 
        res[P] = 1;
        return res;
    }
    long long tm=P;
    for(long long i = 2 ; pow(i,N) <= P; ++i) {
        while(tm % i == 0) {
            ++res[i]; 
            tm /= i;
        }
    }
    if(tm==P) res[P] = 1;
    return res;
}



int main(){
    long long N,P;

    cin>>N>>P;
    long long ans=1;

    if(N==1){
        cout<<P<<endl;
        return 0;
    }


    map<long long ,long long > res=prime_factors(P,N);
    for(auto it = res.begin(); it != res.end(); ++it){
        if(it->second>=N){
            long long test=(it->second/N);
            if(test<=0)test=1;
            ans*=pow(it->first,test);
            
        }
    }



    cout<<ans<<endl;
}