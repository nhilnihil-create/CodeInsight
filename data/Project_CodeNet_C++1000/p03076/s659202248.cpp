#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    vector<int>n(5);
    int ans=644;
    int num=0;
    int a;
    rep(i,5){
        cin>>n.at(i);
    }
    do{
        for(int i=0;i<5;i++){
            if(num%10==0){
                num+=n.at(i);
            }else{
                num+=10-num%10;
                num+=n.at(i);
            }
        }
        if(num<ans){
            ans=num;
        }
        num=0;
    }while(next_permutation(all(n)));

    cout<<ans<<endl;


}