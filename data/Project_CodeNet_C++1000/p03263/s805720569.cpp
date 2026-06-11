#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll h,w;
    cin >> h >> w;
    ll a[h][w];
    ll count=0;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin >> a[i][j];
            count+=a[i][j];
        }
    }
    ll res=0;
    vector<tuple<ll,ll,ll,ll>> ans;
    for(ll i=0;i<h;i++){
        if(i%2==0){
            for(ll j=0;j<w-1;j++){
                if(a[i][j]%2==1){
                    a[i][j+1]++;
                    res++;
                    ans.push_back(make_tuple(i,j,i,j+1));
                }
            }
            if(i!=h-1&&a[i][w-1]%2==1){
                a[i+1][w-1]++;
                res++;
                ans.push_back(make_tuple(i,w-1,i+1,w-1));
            }
        }
        else{
            for(ll j=w-1;j>0;j--){
                if(a[i][j]%2==1){
                    a[i][j-1]++;
                    res++;
                    ans.push_back(make_tuple(i,j,i,j-1));
                }
            }
            if(i!=h-1&&a[i][0]%2==1){
                a[i+1][0]++;
                res++;
                ans.push_back(make_tuple(i,0,i+1,0));
            }
        }
    }
    cout << res << endl;
    for(ll i=0;i<res;i++){
        cout << get<0>(ans[i])+1 << " " << get<1>(ans[i])+1 << " " << get<2>(ans[i])+1 << " " << get<3>(ans[i])+1 << endl;
    }
}
