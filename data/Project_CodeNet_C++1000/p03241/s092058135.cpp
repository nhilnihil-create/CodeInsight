#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    int n,m;
    cin >> n >> m;
    int jogen=m/n;
    int ans=0;
    for(int i=1; i<=min((int)sqrt(m),jogen); i++){
        if(m%i==0) {
            ans=i;
            if(m/i<=jogen){
                ans=m/i;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}