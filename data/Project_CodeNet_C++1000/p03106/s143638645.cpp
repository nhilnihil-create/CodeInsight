#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
    std::ios::sync_with_stdio(false);
    int a,b,k,cot=0;
    cin>>a>>b>>k;
    for(int i=min(a,b);i>=1;i--){
        if(a%i==0&&b%i==0){
            //cout<<i<<endl;
            cot++;
        }
        if(k==cot){
            cout<<i<<endl;
            return 0;
        }
    }
}

