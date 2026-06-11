#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    int a[N];
    for(int i=0;i<N;i++) cin >> a[i];

    int ma=-1e7;
    int i_max;
    int mi=1e7;
    int i_min;
    for(int i=0;i<N;i++){
        if(ma<=a[i]){
            ma=a[i];
            i_max=i;
        }
        if(mi>=a[i]){
            mi=a[i];
            i_min=i;
        }
    }
    vector<pair<int,int>> ans;
    //cout << ma << mi << endl;
    if(ma+mi>=0){
        for(int i=0;i<N;i++){
            if(a[i]<0){
                ans.push_back({i_max,i});
            }
        }
        for(int i=0;i<N-1;i++){
            ans.push_back({i,i+1});
        }
    }else{
        for(int i=0;i<N;i++){
            if(a[i]>0){
                ans.push_back({i_min,i});
            }
        }
        for(int i=N-1;i>0;i--){
            ans.push_back({i,i-1});
        }
    }
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    }

}