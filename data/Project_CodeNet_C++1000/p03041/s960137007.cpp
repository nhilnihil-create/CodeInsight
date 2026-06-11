#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n,k;
    string s;
    cin >> n >> k;
    cin >> s;
    string s2;
    s2=s[k-1];
    if(s2=="A"){
        s[k-1]='a';
    }
    else if(s2=="B"){
        s[k-1]='b';
    }
    else{
        s[k-1]='c';
    }

    cout << s << endl;
    

    return 0;
}