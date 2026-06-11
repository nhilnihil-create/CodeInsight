#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
 
int main(){
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    ll x=x2-x1;
    ll y=y2-y1;
    ll nrm=sqrt(x*x+y*y);
    
    ll x3,y3,x4,y4;
    x3=x2-y; y3=y2+x;
    x4=x1-y; y4=y1+x;
    cout<<x3<<" ";
    cout<<y3<<" ";
    cout<<x4<<" ";
    cout<<y4<<endl;
    return 0;
}