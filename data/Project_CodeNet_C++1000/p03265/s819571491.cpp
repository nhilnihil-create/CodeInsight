#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    int a=x2-x1;
    int b=y2-y1;

    cout<<x2-b<<" "<<y2+a<<" "<<x2-a-b<<" "<<y2+a-b<<"\n";
    return 0;
}