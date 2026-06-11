#include <iostream>
#include <vector>
using namespace std;
int n,b[200],i;
vector<int> ans;
int main(){
    cin>>n;
    for(i=1;i<=n;i++)cin>>b[i];
    
    while(n){
        for(i=n;i&&b[i]!=i;i--){}
        if(!i){
            cout<<-1<<endl;
            return 0;
        }
        ans.push_back(i);
        for(;i<=n;i++)b[i]=b[i+1];
        n--;
    }
    for(i=ans.size()-1;i>=0;i--)cout<<ans[i]<<endl;
    return 0;
}
