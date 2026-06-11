#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
    long N, M;
    cin>>N>>M;
    long A[N];
    for(int i=0;i<N;++i){
        cin>>A[i];
    }

    long mod[N];
    long sum = 0;
    for(int i=0;i<N;++i){
        sum += A[i]%M;
        sum %= M;
        mod[i] = sum;
    }
    
    vector<long> numarr;
    map<long, long>nummap;
    for(int i=0;i<N;++i){
        if(nummap[mod[i]]==0) numarr.push_back(mod[i]);
        nummap[mod[i]]++;
    }

    /**
    for(int i=0;i<M;++i){
        cout<<i<<" "<<num[i]<<endl;
    }
    **/
    long ans = 0;
    for(int i=0;i<numarr.size();++i){
        if(numarr[i]==0){
            ans += nummap[numarr[i]];
        }
        if(nummap[numarr[i]]>1){
            ans += nummap[numarr[i]]*(nummap[numarr[i]]-1)/2;
        }
    }
    cout<<ans<<endl;
}
