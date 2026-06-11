#include<bits/stdc++.h>
using namespace std;


int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int cost1,cost2;
    cost1= a*x + b*y;
    int prod= min(x,y);
    cost2= prod*2*c + a*(x-prod) + b*(y-prod);
    int cost3= max(x,y)* 2*c;
    cout<< min(cost3,(min(cost1,cost2)));
    return 0;
}