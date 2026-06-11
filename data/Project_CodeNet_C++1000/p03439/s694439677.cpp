#include<iostream>
using namespace std;
string q(int i){
    string s;
    cout<<i<<endl;
    cin>>s;
    return s;
}
int N;
int main(){
    cin>>N;
    long long l=0LL,r=N-1LL,mid;
    string s,L,R;
    L=q(l);if(L=="Vacant")return 0;
    R=q(r);if(R=="Vacant")return 0;

    while(r-l>1LL){
        s=q(mid=(l+r)/2LL);
        if(s=="Vacant")return 0;
        if((mid-l)%2==0&&s!=L||(mid-l)%2==1&&s==L)r=mid,R=s;
        else l=mid,L=s;
    }
    return 0;
}