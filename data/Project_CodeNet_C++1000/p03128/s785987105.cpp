#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define be begin
#define en end
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ALL(a) (a).be() , (a).en()
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)        //repeat n times
#define REP2(i,s,n) for(int (i)=(s);(i)<(n);(i)++)   //repeat from s to n 
#define REPD(i,n) for(int (i)=(n);(i)>=0;(i)--)      //repeat from n to 0
#define REPD2(i,s,e) for(int (i)=(s);(i)>=(e);(i)--) //repeat from s to e
#define RANGE(i,v) for(auto &(i):v)                  //repeat range
#define ASIZE(a) (sizeof(a) / sizeof(a[0]))          //array size

using LL = long long;

template<typename T> using V = vector< T >;
using Vi = V<int>;
using Vll = V<LL>;
using Vs = V<string>;

const int INF = 1999999999;

LL GCD(LL a,LL b){
    LL t; LL r;
    if(a<b){t=a;a=b;b=t;}
    if(b==0){return a;}
    while(a%b!=0){r=a%b;a=b;b=r;}
    return b;
}

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    Vi num = {0,2,5,5,4,5,6,3,7,6};
    Vi a(m);
    REP(i,m){
        cin>>a[i];
    }
    sort(ALL(a),greater<int>());

    Vi dp(10005,-INF);
    dp[0] = 0;
    REP2(i,1,n+1){
        REP(j,m){
            int ind = i-num[a[j]];
            if(ind<0) continue;
            chmax(dp[i],dp[ind]+1);
        }
        // REP(k,n+1){
        //     cout<<((dp[k]==-INF)?-1:dp[k])<<" ";
        // }
        // cout<<endl;
    }

    int digit = dp[n];
    int matchi_num = n;
    string ans = "";
    REP(i,digit){
        REP(j,m){
            if(matchi_num-num[a[j]]<0) continue;
            if(dp[matchi_num-num[a[j]]] == dp[matchi_num]-1){
                ans += to_string(a[j]);
                matchi_num -= num[a[j]];
                // cout<<"digit : "<<i+1<<" = "<<a[j]<<" nokori:"<<matchi_num<<endl;
                break;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}