#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main(){
int n;
cin>>n;
int a=3;
int b=0;
while(a<=n){
    int c=0;
    for(int i=1;i<=n;i++){
        if(a%i==0) c++;
    }
    if(c==8) b++;
    a+=2;
}
cout<<b<<endl;
}
