#include <bits/stdc++.h>
#include <cmath>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
int main(){
 int n;
 cin>>n;
 if(n==0){
     cout<<0<<endl;
     return 0;
 }
 string ans;
 int cnt =0;
 while(n!=0){
    if(n%2==0){
         ans.push_back('0');
    }
    else{
        ans.push_back('1');
    }
    int x =n;
    n/=-2;
    if(x<0&&x%2!=0)n++;
 }
 reverse(been(ans));
 cout<<ans<<endl;

}
