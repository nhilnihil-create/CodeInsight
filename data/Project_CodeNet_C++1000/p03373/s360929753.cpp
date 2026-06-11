#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    long long min = 10e10;
    long long tmp=0;
    for(int i=0;i<=x+y;i++){tmp=2*c*i+a*max(0, x-i)+b*max(0, y-i);if(tmp<min)min=tmp;}
    cout<<min<<endl;
}