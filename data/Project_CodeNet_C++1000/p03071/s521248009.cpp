#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int a,b;
    cin >> a >> b;
    int ans=0;
    vector <int> s(4);
    s[0]=a;
    s[1]=a-1;
    s[2]=b;
    s[3]=b-1;
    sort(s.begin(),s.end());
    cout << s[2]+s[3] << endl;

    

    return 0;
}