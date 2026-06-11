#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 110000
#define MOD 1000000007
typedef long long ll;
typedef pair<string,int> P;

vector<ll> V;

int main(){
    ll a[1100],sum=0,ans=0,temp=1099511627776,count=0;
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++) cin>>a[i];

    for(int i=0;i<N;i++,sum=0){
        V.push_back(a[i]);
        sum+=a[i];
        for(int j=i+1;j<N;j++){
            sum+=a[j];
            V.push_back(sum);
        }
    }

    while(temp!=0){
        for(int i=0;i<(int)V.size();i++){
            if(((ans+temp) & V[i]) == ans+temp){
                count++;
                //cout<<"unko"<<endl;
            } 
        }
        //cout<<count<<endl;
        if(count>=K) ans+=temp;

        temp/=2;
        count=0;
        //cout<<ans<<endl;
    }

    cout<<ans<<endl;
}
