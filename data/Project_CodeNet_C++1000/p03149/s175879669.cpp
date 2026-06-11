#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
    VI n(4);
    rep(i,4)cin >> n.at(i);
    sort(n.begin(),n.end());
    bool a=true;
    if(n.at(0)!=1)a=false;
    else if(n.at(1)!=4)a=false;
    else if(n.at(2)!=7)a=false;
    else if(n.at(3)!=9)a=false;
    if(a)cout << "YES" << endl;
    else cout << "NO" << endl;
}