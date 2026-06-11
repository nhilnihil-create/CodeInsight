#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    int n=3;
    vector<int> v(3);
    rep(i,3){
        cin >> v.at(i);
    }
    sort(v.begin(),v.end());
    int x=2*v.at(2)-v.at(1)-v.at(0);
    if(x%2==1) x+=3;
    cout << x/2 << endl;
}