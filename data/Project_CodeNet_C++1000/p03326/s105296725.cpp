#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M;

int main(){
    cin>>N>>M;
    vector<long long> a[3];
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            long long num;cin>>num;
            a[j].push_back(num);
        }
    }

    long long res=0;
    for(int bit=0;bit<(1<<3);bit++){
        vector<long long>b;
        for(int i=0;i<N;i++){
            long long tmp=0;
            for(int j=0;j<3;j++){
                if(bit&(1<<j))tmp+=a[j][i];
                else tmp-=a[j][i];
            }
            b.push_back(tmp);
        }
        sort(b.begin(),b.end(),greater<long long>());
        long long sum=0;
        for(int i=0;i<M;i++){
            sum+=b[i];
        }
        res=max(res,sum);
    }
    cout<<res<<endl;
}