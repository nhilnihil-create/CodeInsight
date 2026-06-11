#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const int MOD = 1000000007;
ll cnt =0,ans=0;
bool graph[8][8];
 
const int NUMBER_OF_SAMPLES = 100000000;
int main(){
    int n;  cin >> n;
    ll h[n];
    for(int i=0;i<n;i++){
        cin >> h[i] ;
    }

    int r,l;
    while(1){
        ll all=0;
        for(int i=0;i<n;i++){
            all += h[i];
        }
        if(all ==0){
            break;
        }

        for(int i=0;i<n;i++){
            if(h[i] != 0){
                l = i;
                for(int j=i;j<n;j++){
                    if(j == n-1 || h[j+1] == 0){
                        r = j ;
                        break;
                    }
                }break;
            }
        }

        //cout << l << " " << r << endl;
         cnt =INF;
        for(int i=l;i<=r;i++){
            cnt = min(cnt , h[i]);
        }
        for(int i=l;i<=r;i++){
            h[i] -= cnt;
        }
        ans+=cnt ;
        
        
    }
    cout << ans << endl;
}
