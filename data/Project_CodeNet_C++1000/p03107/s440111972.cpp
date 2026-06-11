#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;
 
int main(){
    string s;
    cin>>s;
    ll o=0;
    ll z=0;
    rep(i,0,s.size()){
        if(s[i]=='0')z++;
        else if(s[i]=='1')o++;
    }
    cout<<min(o,z)*2<<endl;
}