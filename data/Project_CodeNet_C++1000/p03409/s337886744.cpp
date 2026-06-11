#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,ans=0;
    cin >> N;
    vector<pair<int,int>> ab(N),cd(N);
    vector<bool> abunused(N,true);
    for(int i=0;i<N;i++){
        cin >> ab[i].first >> ab[i].second;
    }
    for(int i=0;i<N;i++){
        cin >> cd[i].first >> cd[i].second;
    }

    sort(ab.begin(),ab.end());
    sort(cd.begin(),cd.end());

    for(int i=0;i<N;i++){
        int mx=N,mxy=-1,mxnum=-1;
        for(int j=0;j<N;j++){
            if(cd[i].first<=ab[j].first){
                mx = j;
                break;
            }
        }
        for(int j=0;j<mx;j++){
            if(abunused[j] && mxy<ab[j].second && ab[j].second<cd[i].second){
                mxy = ab[j].second;
                mxnum = j;
            } 
        }
        if(mxy!=-1){
            abunused[mxnum] = false;
            ans++;
        }
    }

    cout << ans << endl;
}