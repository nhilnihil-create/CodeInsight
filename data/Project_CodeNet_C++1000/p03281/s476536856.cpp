#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int>prime(1000005,0);
bool mark[1000005];
int nprime;

void sieve(int n)///FINDING PRIME
{
    int limit=sqrt(n*1.0)+1,s=0;nprime=0;
    mark[1]=true;///true if not prime.
    mark[2]=false;
    prime[nprime++]=2;
    for(int i=3;i<=n;i+=2){
        if(!mark[i]){prime[nprime++]=i;
            if(i<=limit){///karon limit er upor theke n porjonto not prime gula already cuta hoise.
                for(int j=i*i;j<=n;j+=i*2){
                    mark[j]=true;
                }
            }
        }
    }
}

ll nod(ll n)///Number of divisors
{
    ll nod=1,x3=1,sqrtN=sqrt(n)+1;
    for(int i=0;prime[i]<=sqrtN&&i<nprime;i++){
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                x3++;
            }nod*=x3;x3=1;
        }
    }
    if(n>1)nod*=2;

    return nod-1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll dg[201]={0};
    for(int i=1;i<=200;i++){
        for(int j=i;j<=200;j+=i){
            dg[j]++;
        }
    }
    ll n;
    cin>>n;
    ll s=0;
    for(int i=1;i<=n;i+=2){
        if(dg[i]==8)s++;
    }
    cout<<s;
}
