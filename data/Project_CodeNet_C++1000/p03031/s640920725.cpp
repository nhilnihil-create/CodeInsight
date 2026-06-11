#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cmath>
#include<map>

using namespace std;

#define rep(i,N) for(int i=0;i<N;i++) //0から


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
    int n,m;
    cin>>n>>m;
    vector<int> k(m),p(m);
    int s[10][10];
    rep(i,m){
        cin>>k[i];
        rep(j,k[i]){
            cin>>s[i][j];
            s[i][j]--;
        }
    }
    rep(i,m){
        cin>>p[i];
    }
    vector<int> cnt(m); //各組合せで条件k_j個のうちいくつがonか
    int ans=0;
    for(int bit=0; bit<(1<<n);bit++){
        rep(i,m){
            cnt[i]=0;
            rep(j,k[i]){
                if(bit & (1<<s[i][j])) cnt[i]++;
            }
        }
        int cnt2=0; //カウント値の偶奇が一致する数
        rep(i,m){
            if(cnt[i]%2==p[i]) cnt2++;
        }
        if(cnt2==m) ans++;
        //cout<<cnt2<<endl;
    }

    cout<<ans<<endl;

    return 0;
}

