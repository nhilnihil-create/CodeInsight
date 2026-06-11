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

#define MOD ((ll)1e+9 + 7)




//cout<<fixed<<setprecision(10);
int main(){
    int n,k;
    cin>>n>>k;
    int b=0;
    vector<int> cnt;
    for(int i=1;i<=n;i++){
        int tmp=i;
        int cnt2=0;
        while(tmp<k){
            tmp*=2;
            cnt2++;
        }
        cnt.push_back(cnt2);
    }
    sort(cnt.begin(),cnt.end(),greater<int>());

    rep(i,n){
        b+=pow(2,cnt[0]-cnt[i]);
    }

    double ans = (double)b/(double)(n*pow(2,cnt[0]));

    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
    

    return 0;
}

