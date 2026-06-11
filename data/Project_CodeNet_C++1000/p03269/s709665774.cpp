#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010;
int main(){
    int l;cin>>l;
    int n=0;
    for(int i=0;i<100;i++){
        if(l>=(1<<i)){
            n=i+1;
        }else{
            break;
        }
    }
    int m=(n-1)*2;
    int s=(1<<(n-1));
    for(int i=n-2;i>=0;i--){
        if((1<<i)<=l-s){
            s+=(1<<i);
            m++;
        }
    }
    s=(1<<(n-1));
    cout<<n<<" "<<m<<endl;
    for(int i=n-2;i>=0;i--){
        if((1<<i)<=l-s){
            cout<<i+1<<" "<<n<<" "<<s<<endl;
            s+=(1<<i);
        }
    }
    for(int i=1;i<n;i++){
        cout<<i<<" "<<i+1<<" "<<0<<endl;
        cout<<i<<" "<<i+1<<" "<<(1<<(i-1))<<endl;
    }
}
