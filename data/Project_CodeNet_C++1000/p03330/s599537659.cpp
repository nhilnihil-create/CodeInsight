#include"bits/stdc++.h"
using namespace std;
using ll=long long;
template<typename T=ll>inline T in(istream&is=cin){T ret;is>>ret;return ret;}
template<typename T>inline auto vec2(typename vector<T>::size_type h,typename vector<T>::size_type w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}

int main()
{
    ll n=in(),C=in();
    auto d=vec2<ll>(C,C);for(int i=0;i<C;++i)for(int j=0;j<C;++j)d[i][j]=in();
    auto c=vec2<ll>(n,n);for(int i=0;i<n;++i)for(int j=0;j<n;++j)c[i][j]=in()-1;

    auto colors=vec2<ll>(3,C);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            ++colors[(i+1+j+1)%3][c[i][j]];
        }
    }

    ll ans=1000*500*500;
    for(int i=0;i<C;++i){
        for(int j=0;j<C;++j){
            for(int k=0;k<C;++k){
                if(i==j||j==k||k==i)continue;
                ll tmp=0;
                for(int l=0;l<C;++l)tmp+=d[l][i]*colors[0][l];
                for(int l=0;l<C;++l)tmp+=d[l][j]*colors[1][l];
                for(int l=0;l<C;++l)tmp+=d[l][k]*colors[2][l];
                ans=min(ans,tmp);
            }
        }
    }
    cout<<ans<<endl;
}
