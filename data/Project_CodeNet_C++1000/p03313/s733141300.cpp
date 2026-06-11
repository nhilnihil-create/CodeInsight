#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[1<<n];
    multiset<int,greater<int>> s[1<<n];
    for(int i=0;i<(1<<n);i++){
        cin>>a[i];
        s[i].insert(a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++){
            if(!(j&(1<<i))){
                // cout<<i<<" "<<j<<endl;
                for(int l:s[j]){
                    s[j|(1<<i)].insert(l);
                }
                if(s[j|(1<<i)].size()>2){
                    auto itr=s[j|(1<<i)].begin();
                    ++itr,++itr;
                    s[j|(1<<i)].erase(itr,s[j|(1<<i)].end());
                    // cout<<s[j|(1<<i)].size()<<endl;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<(1<<n);i++){
        int temp=*(s[i].begin())+*(++s[i].begin());
        ans=max(ans,*(s[i].begin())+*(++s[i].begin()));
        // cout<<ans<<" "<<*(s[i].begin())<<" "<<*(++s[i].begin())<<endl;
        cout<<ans<<endl;
    }
    return 0;
}