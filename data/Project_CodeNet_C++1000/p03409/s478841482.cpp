#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> rp(n);
    vector<pair<int,int>> bp(n);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        rp[i]=make_pair(b,a);
    }
    rep(i,n){
        int c,d;
        cin >> c >> d;
        bp[i]=make_pair(c,d);
    }

    
    
    sort(bp.begin(),bp.end());
    sort(rp.begin(),rp.end(),greater<pair<int,int>>());

    //cout << rp[0].first << rp[1].first << rp[2].first << endl;

    int ans=0;
    int i=0;
    while(i<rp.size()){
        bool z=false;
        int j=0;
        while(j<bp.size()){
            if(rp[i].second-bp[j].first<0 && rp[i].first-bp[j].second<0){
                ans++;
                rp.erase(rp.begin()+i);
                bp.erase(bp.begin()+j);
                z=true;
                break;
            }
            j++;
        }
        if(!z) i++;
    }

    cout << ans << "\n";
    
}