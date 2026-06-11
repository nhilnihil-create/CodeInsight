#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> f(n,vector<int>(10)),p(n,vector<int>(11));
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            cin>>f[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<11;j++){
            cin>>p[i][j];
        }
    }
    ll ans=-10000000000;
    for(int bit=1;bit<(1<<10);bit++){
        vector<int> opentime(10);
        for(int i=0;i<10;i++){
            if(bit&(1<<i)){
                opentime[i]++;
            }
        }
        int prof=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<10;j++){
                if(opentime[j]==1&f[i][j]==1){
                    cnt++;
                }
            }
            prof+=p[i][cnt];
        }
        if(ans<prof){
            ans=prof;
        }
    }
    cout<<ans<<endl;
    return 0;
}