#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
#define ll long long
#define ld long double


int main(){

int n,d,x;
cin>>n>>d>>x;

int total=x;
rep(i,n){
    int j=1,a,count=0;
    cin>>a;
    while(j<=d){
        count++;
        j+=a;
    }
    total+=count;
}

cout<<total;
}