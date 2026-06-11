#include <bits/stdc++.h>
    #include <math.h>
 
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846
 
 
    const int M=1e9+7;
    long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
 
    ll modPow(ll a, ll b){
        if(b==0)
            return 1LL;
        if(b==1)
            return a%M;
        ll res=1;
        while(b){
            if(b%2==1)
                res=mul(res,a);
            a=mul(a,a);
            b=b/2;
        }
        return res;
    }

    void solve (){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        map<int,int>mp;
        for(int i=0;i<n;i+=2)
            mp[a[i]]++;
        vector<pair<int,int>>even;
        for(auto i : mp){
            even.push_back({i.second,i.first});
        }
        mp.clear();
        for(int i=1;i<n;i+=2)
            mp[a[i]]++;
        vector<pair<int,int>>odd;
        for(auto i : mp){
            odd.push_back({i.second,i.first});
        }
        sort(even.begin(),even.end());
        reverse(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        reverse(odd.begin(),odd.end());
        int mini=1e9;
        if(even[0].second!=odd[0].second)
            mini=min(mini,(n/2 - even[0].first)+(n/2 - odd[0].first));
        else{
            if((int)even.size()>=2)
                mini=min(mini,(n/2 - even[1].first)+(n/2 - odd[0].first));
            if((int)odd.size()>=2)
                mini=min(mini,(n/2 - even[0].first)+(n/2 - odd[1].first));
            mini=min(mini,(n/2 - even[0].first)+(n/2));
            mini=min(mini,(n/2 - odd[0].first)+(n/2));
        }
        cout<<mini;
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
//        freopen("timber_input.txt", "r", stdin);
//        freopen("timber_output.txt", "w", stdout);
        int t=1;
        // cin>>t;
        for(int i=1;i<=t;i++){
//            cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }