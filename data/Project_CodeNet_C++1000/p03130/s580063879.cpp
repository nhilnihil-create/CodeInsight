#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const ll T = 1e9+7;
int main(){
        vector<ll> t(4);
        ll w[4][4]={};
        ll a,b;
        for(int i=0;i<3;i++){
                cin >> a >> b;
                t[a-1]++;t[b-1]++;
        }
        sort(t.begin(),t.end());
        if(t[0]==1&&t[1]==1&&t[2]==2&&t[3]==2) cout << "YES";
        else cout << "NO";  
        return 0;
}