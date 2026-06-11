# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int n,k,arr[105];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }    
    sort(arr+1,arr+n+1);
    int x=k;
    for(int i=1;i<=n;i++){
        if(x<arr[i]){
            cout<<i-1<<endl;
            return 0;
        }
        x-=arr[i];
    }
    if(x>0) cout<<n-1<<endl;
    else cout<<n<<endl;

}