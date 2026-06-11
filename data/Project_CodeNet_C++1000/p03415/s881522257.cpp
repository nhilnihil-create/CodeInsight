#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    string s1, s2, s3; cin>>s1>>s2>>s3;
    cout<<s1[0]<<s2[1]<<s3[2]<<endl;
    return 0;
}