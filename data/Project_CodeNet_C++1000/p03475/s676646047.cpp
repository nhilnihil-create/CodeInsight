#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    vector<int> c(n-1),s(n-1),f(n-1);
    for(int i=0;i<n-1;i++){
        cin>>c[i]>>s[i]>>f[i];
    }
    vector<int> ans(n);
    for(int i=0;i<n-1;i++){
        int res=0;
        for(int j=i;j<n-1;j++){
            if(j==i){
                res+=s[j];
                res+=c[j];
                continue;
            }
            if(res<=s[j]){
                res=s[j]+c[j];
                continue;
            }            
            int num;
            if(0==(res-s[j])%f[j]){
                num=(res-s[j])/f[j];
            }else{
                num=(res-s[j])/f[j]+1;
            }
            res=s[j]+num*f[j]+c[j];
        }
        ans[i]=res;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}