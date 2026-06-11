#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int n;
vin a(11);
int m=inf;

void dfs(int res,int tmp,int sum){
    if(res==11){
        if((n-tmp)%81==0&&0<=(n-tmp)/81&&(n-tmp)/81<=8){
            sum+=(n-tmp)/81;
            m=min(m,sum);
        }
        return;
    }
    res++;
    if(res<8)for(int i=0;i<=min(5,n/a[res-1]);i++){
        tmp+=a[res-1]*i;
        sum+=i;
        dfs(res,tmp,sum);
        tmp-=a[res-1]*i;
        sum-=i;
    }
    else if(res==8)for(int i=0;i<=min(3,n/a[res-1]);i++){
        tmp+=a[res-1]*i;
        sum+=i;
        dfs(res,tmp,sum);
        tmp-=a[res-1]*i;
        sum-=i;
    }
    else for(int i=0;i<=min(8,n/a[res-1]);i++){
        tmp+=a[res-1]*i;
        sum+=i;
        dfs(res,tmp,sum);
        tmp-=a[res-1]*i;
        sum-=i;
    }
}

int main(){
    cin>>n;
    a[0]=1;
    rep(i,6)a[i+1]=6*a[i];
    a[7]=9;
    a[8]=729;//計算量を減らすには81をなくすのが最も良い
    rep2(i,9,11)a[i]=9*a[i-1];
    int res=0;int tmp=0;int sum=0;
    dfs(res,tmp,sum);
    cout<<m<<endl;
}