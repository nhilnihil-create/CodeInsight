#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
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
const double PI = acos(-1);
int main(){
    int n;cin>>n;
    int r =0,l=n-1,m=(l+r)/2;
    cout<<r<<endl;
    string b,s;
    cin>>b;
    if(b=="Vacant"){
        return 0;
    }
    cout<<l<<endl;
    cin>>s;
    if(s=="Vacant"){
        return 0;
    }
    rep(i,100){
        cout<<m<<endl;
        cin>>s;
        if(s=="Vacant"){
            return 0;
        }
        if((m-r)%2){
            if(b==s){
                l=m;
            }
            else{
                r=m;
                b=s;
            }
        }
        else{
            if(b==s){
                r=m;
                b=s;
                //cout<<400<<endl;
            }
            else{
                l=m;
            }
        }
        m=(l+r)/2;
    }
}