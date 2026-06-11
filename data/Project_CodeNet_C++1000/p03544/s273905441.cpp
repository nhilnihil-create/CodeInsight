#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long l[88];
    l[0]=2;
    l[1]=1;
    if(n==1)cout<<1<<endl;
    else{
        for(int i=2;i<=n;i++){
            l[i]=l[i-1]+l[i-2];
        }
        cout<<l[n]<<endl;
    }
    return 0;
}