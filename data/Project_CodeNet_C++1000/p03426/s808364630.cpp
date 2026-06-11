#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;

int main() {
    map<ll,pair<ll,ll>> dic;
    ll h,w,d;
    cin>>h>>w>>d;
    ll a[h+1][w+1];
    rep(i,h){
        rep(j,w){
            cin>>a[i+1][j+1];
            dic[a[i+1][j+1]]=make_pair(i+1,j+1);
        }
    }
    ll a1[d+1][(h*w)/d+10];
    //a1[i][j]はiからd*j+iまでの魔力
    for (int i=1;i<d+1;i++){
        for (int j=0;d*j+i<=h*w;j++){
            if (j==0){
                a1[i][j]=0;
            }
            else{
                ll num=d*j+i;
                ll x,y;
                x=dic[num].first;
                y=dic[num].second;
                ll x1,y1;
                x1=dic[num-d].first;
                y1=dic[num-d].second;
                a1[i][j]=a1[i][j-1]+abs(x-x1)+abs(y-y1);
            }
        }
    }
    ll q;
    cin>>q;
    rep(i,q){
        ll l,r;
        cin>>l>>r;
        ll d1=(l-1)%d+1;
        ll d2=(l-1)/d;
        ll d3=(r-1)/d;
        cout<<a1[d1][d3]-a1[d1][d2]<<endl;
    }





    return 0;
}