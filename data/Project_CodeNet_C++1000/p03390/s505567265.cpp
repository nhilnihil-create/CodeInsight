#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
 
int main(void){
    int n;
    cin>>n;
    rep(i,n){
        ll a,b;
        cin>>a>>b;
        ll mul = a*b;
        if(mul == 4 && a!=2){
            cout<<1<<endl;
        }else{
            ll root = sqrt(mul);
            if(root*(root+1) < mul){
                cout<<root*2 - 1<<endl;    
            }else if(root*root == mul && a!=b){
                cout<<root*2 - 3<<endl;
            }else{
                cout<<root*2 - 2<<endl;
            }
        }
    }
    return 0;
}