# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int n,arr[105];
vector<int>ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int cnt=n;
    bool ada;
    for(int k=1;k<=n;k++){
         ada=false;
        for(int i=cnt;i>=1;i--){
            if(arr[i]==i){
                ada=true;
                ans.pb(i);
                for(int j=i+1;j<=cnt;j++){
                    arr[j-1]=arr[j];
                }
                break;
            }
        }
        if(!ada){
            break;
        }
        cnt--;
    }
    if(!ada){
        cout<<-1<<endl;
        return 0;
    }
    reverse(ans.begin(),ans.end());
    for(auto isi:ans){
        cout<<isi<<endl;
    }
}