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
    string s;
    cin >> s;
    string ans = "keyence";
    int n= s.size();
    if(s==ans){
        cout<<"YES"<<endl;
        return 0;
    }
    rep(i,-1,n){
        rep(j,i+1,n+1){
            string a;
            rep(k,0,n){
                
                if(k>i&&k<j){
                    continue;
                }
                a.push_back(s[k]);
            }
            if(a==ans){
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    
    

  return 0;
}