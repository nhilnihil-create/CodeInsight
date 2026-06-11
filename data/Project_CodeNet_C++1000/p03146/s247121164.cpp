#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int func(int n){
    if(n%2==0){
        return n/2;
    }else{
        return 3*n+1;
    }
}

int main(){
    int s;cin>>s;
    set<int>num;
    num.insert(s);
    int tmp=s;
    int ans=1;
    while(1){
        tmp=func(tmp);
        if(num.count(tmp)){
            ans++;
            break;
        }else{
            num.insert(tmp);
            ans++;
        }
    }
    cout<<ans<<endl;

}