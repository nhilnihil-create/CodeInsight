#include <bits/stdc++.h>

using namespace std;

int main(){
    int l;
    cin>>l;
    int n;
    vector<array<int,3>> ans;
    int i;
    for(i=21;i>-1;i--){
        if(l&(1<<i)){
            // l-=(1<<i);
            break;
        }
    }
    n=i+1;
    for(int i=1;i<n;i++){
        ans.push_back(array<int,3>({i,i+1,0}));
        ans.push_back(array<int,3>({i,i+1,(1<<(i-1))}));
    }
    int temp=(1<<i);
    for(--i;i>-1;i--){
        if(l&(1<<i)){
            ans.push_back(array<int,3>({i+1,n,temp}));
            temp+=(1<<i);
        }
    }
    cout<<n<<" "<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
    }
    return 0;
}