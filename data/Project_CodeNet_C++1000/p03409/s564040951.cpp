#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
int main() {
    int n;
    cin>>n;
    vector<tuple<int,int,int>> vec;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        vec.push_back(make_tuple(a,b,1));
    }
    rep(i,n){
        int a,b;
        cin>>a>>b;
        vec.push_back(make_tuple(a,b,2));
    }
    
    sort(all(vec));
    //cout<<get<1>(vec[0])<<get<2>(vec[0])<<endl;
    int ans=0;
    for (int i=0;i<n*2;i++){
        if (get<2>(vec[i])==2){
            //自身より前でy座標最大のものと組む
            int index=-1;
            int now=-1;
            for (int j=0;j<i;j++){
                if (get<2>(vec[j])!=1){
                    continue;
                }
                else{
                    if (get<1>(vec[j]) < get<1>(vec[i]) && now < get<1>(vec[j])){
                        index=j;
                        now=get<1>(vec[j]);
                    }
                }
                }
            if (index!=-1){
                get<2>(vec[index])=-1;
                ans+=1;
            }
            
        }

    }
    cout<<ans<<endl;

    return 0;
}