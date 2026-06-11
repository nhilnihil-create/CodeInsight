#include<bits/stdc++.h>
using namespace std;
int c[105];
int main(){
    int n;
    cin >> n;
    pair<int,int> a[n];
    pair<int,int> b[n];
    for(int i=0;i<n;i++){
        cin >> a[i].second >> a[i].first;
        a[i].first *= -1;
    }
    for(int i=0;i<n;i++)cin >> b[i].first >> b[i].second;
    sort(a,a+n);
    sort(b,b+n);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i].second<b[j].first && -a[i].first<b[j].second && c[j]==0){
                c[j]++;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}