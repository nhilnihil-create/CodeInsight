#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cmath>


using namespace std;

#define rep(i,N) for(int i=0;i<N;i++) //0から
#define REP(i,N) for(int j=i;j<N;j++) //iから

typedef long long ll;




ll binary_search(vector<ll> a, ll n, ll key){
    ll right = n, left = -1;
    ll md = (right + left) / 2;

    while(right - left > 1){
        if(a[md] <= key){
            right = md;
        }else{
            left = md;
        }
        md = (right + left) / 2;
    }
    if(left == -1) return -1; //無い場合
    return right;
}

vector<ll> prime;
void Prime(ll n){ //線形篩,素数列挙
    vector<ll> p(n,0);
    p[0]=1;
    p[1]=1;
    for(ll i=2;i<n;i++){
        if(p[i]==0){
            prime.push_back(i);
            p[i]=i;
        }
        ll k=prime.size();
        for(ll j=0;j<k && i*prime[j]<n && prime[j]<=p[i];j++){
            p[i*prime[j]]=prime[j];
        }
    }
}

#define MOD ((ll)1e+7 + 9)




//cout<<fixed<<setprecision(10);
int main(){
    int n;
    cin>>n;
    n--;
    vector<int> c(n),s(n),f(n);
    rep(i,n){
        cin>>c[i]>>s[i]>>f[i];
    }
    int ans=0;
    rep(j,n){
        ans=0;
        for(int i=j;i<n;i++){
            if(ans<=s[i]){
                ans=s[i]+c[i];
            }
            else{
                int k=(ans-s[i])/f[i];
                if((ans-s[i])%f[i]!=0) k++;
                ans=s[i]+k*f[i]+c[i];
            }
        }
        cout<<ans<<endl;
    }
    cout<<0<<endl;

    return 0;
}

