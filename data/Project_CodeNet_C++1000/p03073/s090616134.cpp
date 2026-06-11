#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    string s,a="1",b="0";
    cin>>s;
    long long n=s.size(),ansa=0,ansb=0;
    f(i,1,n){
        if(i%2==1){
            a+='0';
            b+='1';
        }
        else{
            b+='0';
            a+='1';
        }
    }
    f(i,0,n){
        if(s[i]!=a[i]){
            ansa++;
        }
        else if(s[i]!=b[i]){
            ansb++;
        }
    }
    cout<<min(ansa,ansb)<<endl;
    return 0;
}
