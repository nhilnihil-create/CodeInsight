
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 10000007
#define PI 3.14159265359
#define dij priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
typedef long long ll;
//
int main(){
    string s;
    cin>>s;
    
    int ma=0;
    FOR(i,1,s.length()){
      
        FOR(j,0,s.length()-1-i+1){
            bool flag=true;  
            string t=s.substr(j,i);
//            cout<<t<<endl;
            for(auto e:t){
                if(e!='A'&&e!='T'&&e!='G'&&e!='C')flag=false;
            }
            if(flag)ma=i;
        }
    }
    cout<<ma<<endl;
}
