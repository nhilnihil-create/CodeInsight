#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)


int main(){
    int n,a,b; cin >> n >> a >> b;
    int al = (b-a)/2;
    int bo = (b-a-1)/2;
    if((b-a-1)==0){
        cout << "Borys" << endl;
    }else if(al == bo){
        cout << "Borys" << endl;
    }
    else cout << "Alice" << endl;

}