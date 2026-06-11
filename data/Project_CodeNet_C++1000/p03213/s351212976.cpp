#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int sz=110;
vector<int> prime;
int siz;
bool mark[sz];
void seive()
{
    int i,j,k,sq;
    sq=sqrt(sz);
    for(i=3;i<sz;i+=2) mark[i]=true;

    for(i=3;i<=sq;i+=2){
        if(mark[i]){
            for(j=i*i;j<sz;j+=i) mark[j]=false;
        }
    }
    prime.push_back(2);
    for(i=3;i<sz;i+=2) if(mark[i]) prime.push_back(i);
}

int fun(int n)
{
    int i,j,k;
    seive();
    siz=prime.size();
    int sum[siz];

    memset(sum,0,sizeof sum);
    for(i=0;i<siz;i++){
        int tit=prime[i];
        while(tit<=n){
            sum[i]+=(n/tit);
            tit*=prime[i];
        }
    }

    int ans=0;

    for(i=0;i<siz;i++){
        if(sum[i]>=74) ++ans;
        for(j=i+1;j<siz;j++){
            if(sum[i]>=2 && sum[j]>=24) ++ans;
            if(sum[j]>=2 && sum[i]>=24) ++ans;

            if(sum[i]>=4 && sum[j]>=14) ++ans;
            if(sum[j]>=4 && sum[i]>=14) ++ans;

            for(k=j+1;k<siz;k++){
                if(sum[i]>=2 && sum[j]>=4 && sum[k]>=4) ++ans;
                if(sum[j]>=2 && sum[k]>=4 && sum[i]>=4) ++ans;
                if(sum[k]>=2 && sum[j]>=4 && sum[i]>=4) ++ans;
            }
        }
    }

    return ans;
}
int main()
{
    int n;
    cin>>n;
    int ans=fun(n);
    cout<<ans<<'\n';
}
