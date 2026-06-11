#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "



int main(){
    string s;cin>>s;
    if(s.size()==1){co(s);return 0;}
    int ans1 = 0;
    ans1 += (atoi(s.substr(0,1).c_str())-1);
    rep(i,s.size()-1){
        ans1 += 9;
    }
    int ans2 =0;
    rep(i,s.size()){
        ans2+=atoi(s.substr(i,1).c_str());
    }
    co(max(ans1,ans2));
}
