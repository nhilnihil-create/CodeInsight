#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;

vi prime_factrize(int n){
    vi prime_factrize_ret;
    int temp=n;
    for(int i=2;i*i<=n;i++){
        while(temp%i==0){
            prime_factrize_ret.push_back(i);
            temp/=i;
        }
    }
    if(temp!=1) prime_factrize_ret.push_back(temp);
    return prime_factrize_ret;
}

int main(){
    map<int,int> mp;
    map<int,int> mp2;
    for(int i=2;i<=1e5;i++){
        vi temp=prime_factrize(i);
        if(temp.size()==1){
            mp[i]++;
            mp2[i*2]++;
        }
    }
    vi ans(1e5+1);
    for(auto x:mp){
        if(mp2[x.first+1]!=0){
            ans[x.first]=1;
        }
    }
    for(int i=1;i<=1e5;i++){
        ans[i]+=ans[i-1];
    }
    int q;
    cin >> q;
    rep(i,q){
        int l,r;
        cin >> l >> r;
        cout << ans[r]-ans[l-1] << endl;
    }

}