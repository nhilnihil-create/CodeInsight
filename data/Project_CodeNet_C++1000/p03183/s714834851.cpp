/***
**   AUTHOR::ASHUTOSH MOUDGIL
***/


#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F first
#define S second
#define int long long
//#define ll long long
#define all(x) x.begin(),x.end()
#define rsort(x) sort(all(x)); reverse(all(x));
#define endl '\n'
#define vi vector<int>
#define vlli vector<long long>
#define pii pair<int,int>
#define mod 1000000007
#define LMAX 1e18
#define deb(x) cout<<#x<<" : "<<x<<endl;
#define PI 3.141592654
#define deb1(x) cout << #x <<"="<< x <<endl;
#define deb2(x,y) cout << #x <<"="<<x<<", "<<#y<<"="<<y <<endl;
#define deb3(x,y,z) cout << #x <<"="<<x<<", "<<#y<<"="<<y <<", "<<#z<<"="<<z<<endl;
#define deb4(x,y,z,a) cout << #x <<"="<<x<<", "<<#y<<"="<<y <<", "<<#z<<"="<<z<< ", "<<#a <<"="<<a << endl;
#define debarr(x) cout << #x<<"::"<<endl;for(int i : x){cout << i <<" ";} cout <<endl;

inline void add(int& a, int b){a = (a+b); if(a>=mod)a-=mod;}
inline void sub(int& a, int b){a = a-b; if(a<0)a+=mod;}
inline void mul(int& a, int b){a = (a*b)%mod;}

const int N = 3e4;
int n;
vi dp(N+1,0);

vector<pair<int,pair<int,int>>> arr;
bool cmp(pair<int,pair<int,int>> a , pair<int,pair<int,int>> b){
    return a.F+a.S.F < b.F+b.S.F;
}

void mymain(){
    cin >> n;
    arr.resize(n);
    int mw=INT_MAX,jj=-1;
    for(int i=0;i<n;i++){
        cin >> arr[i].S.F >> arr[i].F >> arr[i].S.S;
    }
    sort(all(arr),cmp);
    /*for(int i=0;i<n;i++){
        if(arr[i].S.F < mw){
            mw = arr[i].S.F;
            jj=i;
        }
    }*/


    //dp[arr[0].S.F] = arr[0].S.S;
    //for(int i : dp)
     //   cout << i <<" ";
    //cout << endl;
    for(int i=0;i<n;i++){
        //if(i==jj)
         //   continue;
        int w = arr[i].S.F,s=arr[i].F,v=arr[i].S.S;
        //vi ndp(dp);
        //for(int i=0;i<N;i++)
        //    ndp[i]=dp[i];

        for(int j=s;j>=0;j--){
                if(w+j <= N)
                dp[w+j] = max(dp[w+j],dp[j]+v);
        }
        //ndp[w] = max(ndp[w],v);
       // deb(i)
       // debarr(ndp)
        //dp = ndp;
    }

    int ans = 0;
    for(int i : dp)
        ans = max(ans,i);//,cout << i <<" ";
        //cout << endl;
    cout << ans <<endl;
}

signed main(){
IOS;
///freopen("input.txt", "r", stdin);
///freopen("output.txt", "w", stdout);
int t=1;
///cin>>t;

for(int tt=0;tt<t;tt++){
   ///cout << "Case #" << tt+1 <<": ";
   mymain();
   }
return 0;
}
/*

*/
