#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    int y;
    vector<int> ans(3,-1);
    cin>>n>>y;
    for(int i=0;i<=y/10000;i++){
        for(int j=0;j<=(y-10000*i)/5000;j++){
            int k = (y-(10000*i + 5000*j))/1000;
            if(i+j+k == n){
                ans.at(0)=i;
                ans.at(1)=j;
                ans.at(2)=k;
                break;
            }
        }
    }
    cout<<ans.at(0)<<' '<<ans.at(1)<<' '<<ans.at(2);

}