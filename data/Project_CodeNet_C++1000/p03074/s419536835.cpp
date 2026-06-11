#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=1<<18;


int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> c(0);
    if(s[0]=='0') c.push_back(0);
    if(n==1) c.push_back(1); 
    for(int i=1;i<n;i++){
        int seq=1;
        while(i<n && s[i]==s[i-1]){
            i++;
            seq++;
        }
        c.push_back(seq);
    }
    if(n>1 && s[n-1]!=s[n-2]) c.push_back(1);

    int sum=0;
    int m=c.size();
    for(int i=0;i<=min(2*k,m-1);i++){
        sum+=c[i]; 
    }
    int ans=sum;
    for(int i=2*k+1;i<m;i+=2){
        sum-=c[i-2*k-1];
        sum-=c[i-2*k];
        sum+=c[i];
        if(i+1<m) sum+=c[i+1];
        ans=max(ans,sum);
        //cout<<sum<<endl;
    }
    cout<<ans<<endl;
 
}