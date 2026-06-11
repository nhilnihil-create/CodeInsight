//AcCepted

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end()
#define pb push_back
const int inf = 2147483647;

int main (){
    string s;cin>>s;
    bool flag = true;
    if(s[0]!='A')flag=false;
    int c=0;
    rep(i,1,s.size()){
        if(isupper(s[i])){
            if(i==1||i==s.size()-1||s[i]!='C')flag=false;
            else if(s[i]=='C')c++;
        }
    }
    if(c>1||c==0)flag=false;
    cout << (flag ? "AC" : "WA")<< endl;
    return 0;
}