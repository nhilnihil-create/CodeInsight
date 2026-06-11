#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> st;

ll S(ll x)
{
    ll ret=0;
    while(x) ret+=x%10,x/=10;
    return ret;
}

int main()
{
    ll k; scanf("%lld",&k);
    st.clear();
    for(int i=1;i<=9;i++) st.insert(i);
    for(int i=1;i<=9;i++) st.insert(i*10+9);
    ll now=99,base=100;
    while(now<=(ll)1e15)
    {
        while(S(now+base)*base>=now+base) 
        {
            now+=base;
            st.insert(now);
        }
        base*=10;
    }
    while(k--)
    {
        printf("%lld\n",*st.begin());
        st.erase(st.begin());
    }
}