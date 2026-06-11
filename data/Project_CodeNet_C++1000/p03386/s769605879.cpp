#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
#define ll long long
#define ld long double


int main(){

int a,b,k;
cin>>a>>b>>k;
int c= 2*k;

if((b-a+1)<=c )
{
    while(a<=b){
        cout<<a<<endl;
        a++;
    }
}else{
    int d=a+k-1;
    while(a<=d){
        cout<<a<<endl;
        a++;
    }
    a= b-k+1;
    while(a<=b){
        cout<<a<<endl;
        a++;
    }
}

}