#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


string s[20];
void make(int h,int w){
    for(int j=0;j<h;j++)for(int i=0;i<w;i++) s[j]+='.';
}
void dbg(int h,int w){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cerr<<s[i][j];
        }
        cerr<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    int h,w,n;
    cin>>w>>h>>n;
    vector<vector<int>> v(h);
    // make(h,w);
    int wall[h]={};
    for(int i=0;i<h;i++) wall[i] = i-1;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        x--,y--;
        // s[y][x]='#';
        if(wall[y]+1==x) wall[y] = x;
        v[y].push_back(x);
    }
    //dbg(h,w);
    for(int i=0;i<h;i++){
        sort(v[i].begin(),v[i].end());
    }
    int ans = w;
    for(int i=0;i<h;i++){
        if(i) wall[i] = max(wall[i],wall[i-1]+1);
        if(v[i].size()==0) continue;
        if(i==0){
            ans = v[i][0];
            continue;
        }
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]<=wall[i]+1){
                wall[i] = max(wall[i],v[i][j]);
                continue;
            }
            if(v[i][j]>=ans) break;
            if(j==0){
                ans = v[i][j];
                break;
            }
            if(v[i][j-1]+1 == v[i][j]) continue;
            ans = v[i][j];
            break;
        }
        //cerr << i << " " << ans << " "<< wall[i]<<endl;
    }
    cout << ans << endl;

}