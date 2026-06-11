#include<bits/stdc++.h>
#include<boost/algorithm/string/replace.hpp>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::algorithm;
using namespace boost::multiprecision;
 
#define rep(i,n) for(int i=0 ; i<(n) ; i++)
#define repr(i,n) for(int i=(n) ; i>=0 ; i--)
#define ALL(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long ull;
 
const ll INF = 1LL<<60;
const int mINF = 1e9;
const int MOD = 1e9+7;

template<typename T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
T GCD(T a,T b){ return b ? GCD(b,a%b) : a ;}
template<typename T>
T LCM(T a,T b){ return a*b / GCD(a,b) ;}

template<typename T>//文字列の置換/Boost:replace_all()
T replace_str(T str, string target, string str_to) {
    string::size_type pos = 0;
    while (pos = str.find(target, pos), pos != string::npos) {
        str.replace(pos, target.length(), str_to);
        pos += str_to.length();
    }
    return str;
}

int main(){
    int a,b,c,x,y;
    cin >>a>>b>>c>>x>>y;
    int z = abs(x-y);
    int buy = ((x+y) - z) / 2;
    int ans = 0;
    if(a+b < c*2){
        ans += a * buy + b * buy;
    }else{
        ans += c * buy * 2;
    }

    if(x>y){
        if(a > c*2){
            ans += c * z * 2;
        }else{
            ans += a * z;
        }
    }else{
        if(b > c*2){
            ans += c * z * 2;
        }else{
            ans += b * z;
        }
    }
    cout << ans << endl;
    return 0;
}