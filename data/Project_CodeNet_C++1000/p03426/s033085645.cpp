#include<bits/stdc++.h>
using namespace std;

map<int,pair<int,int>> mp;
long long int c[90005];
int main(){
    int h,w,d;
    cin >> h >> w >> d;
    int a[h+1][w+1];
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
        cin >> a[i][j];
        mp[a[i][j]]=make_pair(i,j);
    }
    for(int i=d+1;i<=h*w;i++){
        c[i]=c[i-d]+abs(mp[i].first-mp[i-d].first)+abs(mp[i].second-mp[i-d].second);
    }
    int q,l,r;
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> l >> r;
        cout << c[r]-c[l] << endl;
    } 
}