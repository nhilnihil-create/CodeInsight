#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


const ll N=100001;

bool prime[N];

ll ruipri[N];

void eratosthenes(bool prime[N]){
    for(ll i=0;i<N;i++) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for(ll i=0;i<N;i++){
        if(prime[i]){
            for(int j = i + i; j < N; j+=i){
                prime[j] = 0;
            }
        }
    }
}

int main(){

    eratosthenes(prime);

     ll count=0;
   

    for(ll i=1;i<N;i++){
    
        
       
        if(i%2==1){
            ll k=(i+1)/2;
        if(prime[i]==1&&prime[k]==1){
            ++count;
        }
        }
        ruipri[i]=count;
        
    }
/*
    for(int i=0;i<60;i++){
        cout<<ruipri[i]<<" ";
    }
    cout<<endl;
  */  

    ll Q;
    cin>>Q;

    ll ans[Q];


    for(ll i=0;i<Q;i++){
        ll l,r;
        cin>>l>>r;

        ans[i]=ruipri[r]-ruipri[l-1];


    
    }

    for(ll i=0;i<Q;i++){
        cout<<ans[i]<<endl;
    }




}


