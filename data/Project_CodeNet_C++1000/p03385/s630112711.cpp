#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(s == "abc"){
        cout << "Yes\n";
    }
    else cout << "No\n";
}