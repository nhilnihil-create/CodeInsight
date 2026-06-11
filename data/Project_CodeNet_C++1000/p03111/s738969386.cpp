#include"bits/stdc++.h"
using namespace std;
using ll=long long;
template<class T=ll>inline T in(istream&is=cin){T ret;is>>ret;return ret;}
template<class T>inline auto vec2(class vector<T>::size_type h,class vector<T>::size_type w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}
template<class RandomAccessIterator>inline void psortb(RandomAccessIterator first,RandomAccessIterator last){using P=pair<decltype(first->first),decltype(first->second)>;sort(first,last,[](const P&p1,const P&p2){return p1.second<p2.second||(p1.second==p2.second&&p1.first<p2.first);});}

int main()
{
    ll n=in(),a=in(),b=in(),c=in();
    vector<ll>l(n);for(ll i=0;i<n;++i)l[i]=in();
    ll ans=numeric_limits<ll>::max();
    for(ll i=(1<<(2*n))-1;i>=0;--i){
        ll a_len=0,b_len=0,c_len=0;
        ll a_cnt=0,b_cnt=0,c_cnt=0;
        for(ll j=0;j<n;++j){
            ll foo=(i>>(2*j))&3;
            if(foo==1){
                a_len+=l[j];
                ++a_cnt;
            }else if(foo==2){
                b_len+=l[j];
                ++b_cnt;
            }else if(foo==3){
                c_len+=l[j];
                ++c_cnt;
            }
        }
        if(a_cnt*b_cnt*c_cnt){
            ans=min(ans,(a_cnt+b_cnt+c_cnt-3)*10+abs(a-a_len)+abs(b-b_len)+abs(c-c_len));
        }
    }
    cout<<ans<<endl;
}
