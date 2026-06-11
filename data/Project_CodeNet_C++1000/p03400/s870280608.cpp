#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d,x;
    cin>>n>>d>>x;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a.at(i);
    }
    int ans=0;
    for(int i=0; i<n; i++){
        int j=0,cnt=0;
        while(cnt<d){
            cnt=j*a.at(i)+1;
            if(cnt>d) break;
            if(cnt==d){
                ans++;
                break;
            }
            j++;
            ans++;
        }
    }
    ans=ans+x;
    cout<<ans<<endl;
}