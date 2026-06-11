//KEYENCE String

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / __gcd(a, b) * b
#define range(a) (a).begin(),(a).end()
const int inf = 2147483647;

int main (){
    string s;cin>>s;
    bool flag = false;
    rep(i,0,s.size()){
        rep(j,0,s.size()){
            string ss = s;
            ss = ss.erase(i,j);
            if(ss=="keyence")flag = true;
        }
    }
    cout <<(flag ? "YES" : "NO")<< endl;
    return 0;
}