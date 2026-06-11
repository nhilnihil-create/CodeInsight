#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    int N;
    bool ok;
    cin>>N;
    vector<int> v,ans;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    for(int i=0;i<N;i++){
        ok=false;
        for(int j = v.size()-1;j>=0;j--){
            if((j+1)==v[j]){
                ok=true;
                ans.push_back(v[j]);
                v.erase(v.begin()+j);
                break;
            }
        }
            
        if(ok == false){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<endl;
    
    return 0;
}
