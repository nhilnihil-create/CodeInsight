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
        n=5;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            b[i]=i;
        }
        int mini=1e9;
        while(next_permutation(b.begin(),b.end())){
            vector<int>order(n);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==b[j])
                        order[i]=a[j];
                }
            }
            int total=0;
            for(int i=0;i<n;i++){
                if(i==0)
                    total+=order[i];
                else{
                    while(total%10!=0)
                        total++;
                    total+=order[i];
                }
            }
            mini=min(mini,total);
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