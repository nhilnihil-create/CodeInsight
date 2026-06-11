#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long ll;

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int numa,numb,cost = 0;
    if(a + b <= 2*c){
        cost = a*x + b*y;
    }
    else{
        if(x<y){
            swap(x,y);
            swap(a,b);
        }
        cost = min(2*x*c,2*y*c + (x-y)*a);
    }
    cout<<cost<<endl;
    return 0;
}