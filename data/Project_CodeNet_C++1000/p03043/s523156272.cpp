#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
vector<int> x = {1,-1,0,0};
vector<int> y = {0,0,-1,1};
int main(){
    double n,k;
    double ans = 0;
    cin >> n >> k;
    double end = n;
    int dice = 0;
    while(k>=0.05){
        int basic;
        if(k-int(k)==0){
            basic = k;
        }else{
            basic = int(k)+1;
        }
        
        if(end>=basic){
            ans += (end-basic+1)*pow(2,dice*(-1))/n;
            //cout<<pow(2,dice*(-1))<<basic<<endl;
            end = basic-1;
            if(end==0){
                break;
            }
        }
        
        k/=2;
        
        dice ++;
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
  return 0;
}