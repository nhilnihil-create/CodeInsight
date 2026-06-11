//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int sieve[55556];
vector<int>v;
int32_t main() {
    IOS;
    int n;
    cin>>n;
    for(int i=2;i<=55555;i++)
    {
        if(!sieve[i])
            for(int j=1;i*j<=55555;j++)
                sieve[i*j]=i;
    }
    for(int i=2;i<=55555;i++)
        if(sieve[i]==i)
            v.push_back(i);
    vector<int>ans;
    for(int i=0;;i++)
    {
        if(ans.size()==n)
            break;
        if(v[i]%5 == 1)
            ans.push_back(v[i]);
    }
    for(int i:ans)
        cout<<i<<" "; 
}   

