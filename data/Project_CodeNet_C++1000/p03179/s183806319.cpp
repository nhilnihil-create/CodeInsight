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

int n;
const int N = 3001;
int dp[N][N],pre[N][N];


void mymain(){
    cin >> n;
    string s;
    cin >> s;

    dp[1][1]=1;
    for(int i=2;i<=n;i++){


        for(int j=1;j<n;j++){
            pre[i-1][j] = (pre[i-1][j-1]+dp[i-1][j])%mod;
        }


        for(int j=1;j<=i;j++){
            int L,R;
            if(s[i-2] == '<'){
                L=1,R=j-1;
            }else{
                L=j,R=i-1;
            }

            if(L<=R){
                dp[i][j] = (dp[i][j] + (pre[i-1][R] - pre[i-1][L-1]+mod)%mod)%mod;
            }

            /*
            for(int z = L;z<=R;z++){
                add(dp[i][j],dp[i-1][z]);
            }




            for(int k=1;k<i;k++){
                int rk=k;
                if(j<=k){
                    rk++;
                }
                if(rk < j && s[i-2] == '<'){
                    add(dp[i][j] , dp[i-1][k]);
                }
                if(rk > j && s[i-2] == '>'){
                    add(dp[i][j] , dp[i-1][k]);
                }
            }*/
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++)
        add(ans , dp[n][i]);

    cout << ans << endl;

}

signed main(){
IOS;
///freopen("input.txt", "r", stdin);
///freopen("output.txt", "w", stdout);
int t=1;
//cin>>t;

for(int tt=0;tt<t;tt++){
   ///cout << "Case #" << tt+1 <<": ";
   mymain();
   }
return 0;
}
/*

*/
