#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i,n)cin >> a[i];
    vector<pair<int,int>>dataa(110000);
    vector<pair<int,int>>datab(110000);
    rep(i,110000){
        dataa[i].second = i;
        datab[i].second = i;
        dataa[i].first = 0;
        datab[i].first = 0;
    }
    rep(i,n){
        if(i%2==0){
            datab[a[i]].first++;
        }else {
            dataa[a[i]].first++;
        }
    }
    sort(all(dataa));
    reverse(all(dataa));
    sort(all(datab));
    reverse(all(datab));
    int x = dataa[0].second;
    int y = datab[0].second;
    if(x == y){
        if(dataa[1].first < datab[1].first)y = datab[1].second;
        else x = dataa.at(1).second;
        }
    int ans = 0;
    rep(i,n){
        if(i%2==0){
            if(a[i]!=y)ans++;
        }else{
            if(a[i]!=x)ans++;
        }
    }
    cout << ans << endl;
    //cout << x << " " << y << endl;
    
    return 0;
}