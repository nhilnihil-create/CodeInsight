#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    ll x3,y3,x4,y4;
    ll diffx = x2-x1;
    ll diffy = y2-y1;
    x3=x2-diffy;
    y3=y2+diffx;
    x4=x3-diffx;
    y4=y3-diffy;
    cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;

}

