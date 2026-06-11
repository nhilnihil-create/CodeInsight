#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int a,b,k;
    cin>>a>>b>>k;
    int c;
    rep(i,k){
        if(i%2==0){
            if(a%2==1)a--;
            a/=2;
            b+=a;
        }else{
            if(b%2==1)b--;
            b/=2;
            a+=b;
        }
    }
    cout<<a<<" "<<b<<endl;
}