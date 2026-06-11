#include <iostream>
using namespace std;
typedef long long ll;
char A[200000],B[200000];
ll n,k,s,g,m,ans;
string t;
bool f(ll p,ll q){
    for(int i=0;i<k;i++){
        if(A[i]==t[p]){
            if(B[i]=='L')p--;
            else p++;
        }
    }
    if(p==q)return true;
    return false;
}
int main(void){
    cin>>n>>k>>t;
    t='#'+t+'#';
    for(int i=0;i<k;i++)cin>>A[i]>>B[i];
    s=0,g=n+1;
    while(g-s>1){
        m=(g+s)/2;
        if(f(m,0))s=m;
        else g=m;
    }
    ans+=s;
    s=0,g=n+1;
    //cout<<ans<<endl;
    while(g-s>1){
        m=(g+s)/2;
        if(f(m,n+1))g=m;
        else s=m;
        //cout<<s<<g<<endl;
    }
    ans+=n-s;
    //cout<<ans<<endl;
    cout<<n-ans<<endl;
}
