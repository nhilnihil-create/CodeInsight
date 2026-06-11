//////AGC039-B//////
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(ll i=(n);i<(k);i++)
ll n,m,k,ans=-100;
void Main(){
    cin>>n>>m>>k;
    For(i,0,k){
        if(i%2==0){
            m+=n/2;
            n/=2;
        }
        else{
            n+=m/2;
            m/=2;
        }
    }
    cout<<n<<" "<<m<<endl;
}
int main(){
    Main();
    return 0;
}
