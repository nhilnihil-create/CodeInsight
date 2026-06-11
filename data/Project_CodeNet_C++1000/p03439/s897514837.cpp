#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<list>
#include<unordered_map>
#include <random>
#define ll long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const int INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const int MOD = 1000000007;
const int MAX = 510000;
const double pi = acos(-1);
const double eps = 1e-9;
ll dx[4] ={1,0,-1,0} , dy[4] ={0,1,0,-1};



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    scanf("%lld", &n);
    char right[10],left[10];
    ll low=0,high=n-1;
    printf("0\n");
    fflush(stdout);
    scanf("%s",left);
    if(strcmp(left,"Vacant")==0){
        return 0;
    }
    printf("%lld\n",n-1);
    fflush(stdout);
    scanf("%s",right);
    if(strcmp(right,"Vacant")==0){
        return 0;
    }
    while(true){
        ll mid=(low+high)/2;
        printf("%lld\n",mid);
        fflush(stdout);
        char response[10];
        scanf("%s",response);
        if(strcmp(response,"Vacant")==0){
            return 0;
        }
        if((mid-low)%2==1){
            if(strcmp(left,response)==0){
                high=mid;
                strcpy(right,response);
            }
            else{
                low=mid;
                strcpy(left,response);
            }
        }
        else{
            if(strcmp(left,response)==0){
                low=mid;
                strcpy(left,response);
            }
            else{
                high=mid;
                strcpy(right,response);
            }
            
        }
    }
    return 0;
}
