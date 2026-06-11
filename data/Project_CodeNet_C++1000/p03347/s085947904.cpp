#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int,int> ii;

long long n,a[200005],ans;

int main(){
    cin.tie(0),ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i<=n;i++)
        cin >> a[i];
    if(a[1]!=0){
        cout<<"-1";
        return 0;
    }
    int check1=1;
    for(int i = 2;i<=n;i++){
        if(a[i]>a[i-1]+1) {cout<<"-1"; return 0;}
        if(a[i]==a[i-1]+1) ans++;
        else ans+=a[i];
    }
    cout<<ans;
}
