#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

vector<int> sieve(int n){
    vector<int> prime;
    vector<int> is_prime(n+1, 1);
    int p=0;
    is_prime[0]=0;
    is_prime[1]=0;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            if(i%5 == 2) prime.push_back(i); 
            for(int j=2*i;j<=n;j+=i) is_prime[j]=0;
        }
    }
    return prime;
}

int main(void){
    int n;
    cin>>n;
    vector<int> prime = sieve(55555);
    rep(i, n) cout<<prime[i]<<" ";
    cout<<endl;
    return 0;
}