#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<=(n);i++)
using ll=long long;

int main(){
    int n,y;
    cin>>n>>y;
    int a=-1;
    int b=-1;
    int c=-1;

  
    rep(i,2000){
        rep(j,2000){
                if(10000*i+5000*j+1000*(n-i-j)==y && n-i-j>=0){
                    a=i;
                    b=j;
                    c=n-a-b;
                    break;
                }
            }
            if(a!=-1 && b!=-1)break;
        }
    cout<<a<<' '<<b<<' '<<c;
    return 0;
    }
