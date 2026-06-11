#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    cin >> n >>k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }
    int cnt=k;
    int ans=1;
    while(cnt<n){
        cnt+=k-1;
        ans++;
    }
    cout << ans << endl;
    
}