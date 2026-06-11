#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int a,b,k;
int ans;
int main(void){
    cin>>a>>b>>k;
    for(int i=100;i>=0;i--){
        if(a%i==0&&b%i==0){
            k--;
        }
        if(k==0){
            cout<<i<<endl;
            return 0;
        }
    }

}

