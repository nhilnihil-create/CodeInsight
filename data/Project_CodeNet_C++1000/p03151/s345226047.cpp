#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    int N; cin >> N;
    int a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    int b[N];
    for(int i=0;i<N;i++){
        cin >> b[i];
    }
    int ans=0;
    ll p=0;
    vector<int> c;
    for(int i=0;i<N;i++){
        if(b[i]-a[i]>0){
            p+=b[i]-a[i];
            ans++;
        }else c.push_back(a[i]-b[i]);
    }
    sort(c.begin(),c.end(),greater<int>());
    for(auto tmp:c){
        if(p<=0) break;
        p-=tmp;
        ans++;
    }
    if(p>0){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}