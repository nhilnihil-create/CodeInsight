#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string s;
    cin>>s;
    bool a=false;
    for(int i=0;i<s.size();i++){
        for(int j=0;i+j<s.size();j++){
            if(s.substr(0,i)+s.substr(i+j)=="keyence"){
                a=true;
                break;
            }
        }
    }
    if(a) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}