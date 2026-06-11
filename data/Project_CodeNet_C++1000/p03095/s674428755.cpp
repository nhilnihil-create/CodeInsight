#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){

vector <ll> k(26,1),k2(26,0);

 int ans;
 ans='y';
 int n;
 cin >> n;
 string s;
 cin >> s;
 char ss;
 string s2;
 s2=s[0];
 ss=s[0];
 ans=ss;
    

rep(i,n){
    ss=s[i];
    ans=ss-97;
    ++k[ans];
}

ll se=1;
rep(i,26){
    se*=k[i];
    se=se%1000000007;
}

cout << se-1 << endl;
    

    return 0;
}