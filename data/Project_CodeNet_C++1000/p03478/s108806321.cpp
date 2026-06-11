#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n,a,b;
    cin >> n >> a >> b;
    int ans=0;
    for(int i=1;i<n+1;i++){
        int c=i;
        int sum=0;
        while(true){
            if(c/10==0){
                sum+=c;
                break;
            }
            else{
                sum+=c%10;
                c/=10;
            }
        }
        if(sum>=a&&sum<=b) ans+=i;
    }   
    cout << ans << endl;
}