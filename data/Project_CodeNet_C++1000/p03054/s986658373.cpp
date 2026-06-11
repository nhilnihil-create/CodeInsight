#include <iostream>
using namespace std;
typedef long long ll;
ll h,w,k,U,R,L,D;
string s,t;
void f(char c,ll n){
    if(c=='U'){
        if(n==0)D++;
        else U--;
    }
    else if(c=='D'){
        if(n==0)U++;
        else D--;
    }
    else if(c=='R'){
        if(n==0)L++;
        else R--;
    }
    else {
        if(n==0)R++;
        else L--;
    }
}
int main(void){
    cin>>h>>w>>k>>U>>L;
    cin>>s>>t;
    D=h-U+1;
    R=w-L+1;
    for(int i=0;i<k;i++){
        f(s[i],1);
        if(R*L*U*D==0){
            cout<<"NO"<<endl;
            return 0;
        }
        //cout<<R<<L<<D<<U<<endl;
        f(t[i],0);
        U=min(U,h);
        D=min(D,h);
        R=min(R,w);
        L=min(L,w);
    }
    cout<<"YES"<<endl;
}
