#include<bits/stdc++.h>
using namespace std;
long long m(long long a,long long b){
    long long r=1;
    while(b--){
        r*=a;
    }
    return r;
}
int main(){
    long long n;cin>>n;
    vector<long long> a;
    if(n==0){
        cout<<0;
        return 0;
    }
    long long t=0;
    while(n){
        a.push_back(abs(n%2));
        n-=abs(n%2)*m(-1,t);
        n/=2;
        t++;
    }
    reverse(a.begin(),a.end());
    for(int i=0;i<a.size();i++) cout<<a[i];
    return 0;
}
