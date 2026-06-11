#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <list>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

int main(){
    ll a[6],n1=0,n2=0,n3=0,n4=0;
    rep(i,6){
        cin >> a[i];
        if(a[i] == 1) n1++;
        if(a[i] == 2) n2++;
        if(a[i] == 3) n3++;
        if(a[i] == 4) n4++;
    }

    if(n1==3 || n2==3 || n3==3 || n4==3) cout << "NO" << endl;
    else cout << "YES" << endl;
}
