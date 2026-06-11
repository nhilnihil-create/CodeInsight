#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<ll>;
using P  = pair<ll,ll>;

int main(){
    int a,b,c;
    cin >>a>>b>>c;
    if((c-a)*(b-c)>0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}