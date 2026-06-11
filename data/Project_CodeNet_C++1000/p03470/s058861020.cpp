#include<bits/stdc++.h>
#define ll long long
#define mod 838627288460106
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    fast_io
    ll n,x,i,j;
    set<ll>st;
    cin>>n;
    while(n--){
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<endl;

    return 0;
}



