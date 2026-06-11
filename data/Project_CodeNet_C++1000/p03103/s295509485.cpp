#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    unsigned long long M,N,ans=0;
    cin>>N>>M;
    vector<pair<long,long>>p(N);
    for(int i=0;i<N;i++){
        long long A,B;
        cin>>A>>B;
        p[i]=make_pair(A,B);
    }
    sort(p.begin(),p.end());
    for(int i=0;i<N;i++){
        if(M>=p[i].second){
            M-=p[i].second;
            ans+=p[i].first*p[i].second;
        }else{
            ans+=M*p[i].first;
            break;
        }
    }
    cout<<ans<<endl;
}