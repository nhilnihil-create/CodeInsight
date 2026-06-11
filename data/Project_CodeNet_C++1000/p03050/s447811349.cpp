#include<bits/stdc++.h>
using namespace std;
int main(){
    long N,a=0;
    cin>>N;
    for(long i=1;i*i<N;i++){if(N%i==0&&N/i-1>i)a+=N/i-1;}
    cout<<a<<endl;
}
