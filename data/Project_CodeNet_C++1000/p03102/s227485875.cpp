#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1000000000000
#define MOD 1000000007

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);

    int n,m,c;
    cin>>n>>m>>c;
    int a[m],b[m];
    int ans=0;
    
    for(int j=0; j<m; j++){
        cin>>b[j];
    }
    
    for(int i=0; i<n; i++){
        int sum=c;
        for(int j=0; j<m; j++){
            cin>>a[j];
            sum+=a[j]*b[j];
        }
        
        if(sum>0)   ans++;
    }
    
    cout<<ans<<endl;
    return 0;
}