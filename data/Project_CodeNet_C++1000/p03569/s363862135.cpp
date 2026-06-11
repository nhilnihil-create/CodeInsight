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
int mod =1000000007;
const double PI = acos(-1);
int main(){
    string s;cin>>s;
    int ans =0;
    while(s.size()>1){
        if(s[0]==s.back()){
            s.erase(s.begin());
            s.pop_back();
        }
        else if(s[0]=='x'){
            ans++;
            s.erase(s.begin());
        }
        else if(s.back()=='x'){
            ans++;
            s.pop_back();
        }
        else {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}