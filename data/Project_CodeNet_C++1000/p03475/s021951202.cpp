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
            if(res<=s[j]){
                res=s[j]+c[j];
            }else if(0==res%f[j]){
                res+=c[j];
            }else{
                res+=f[j]-res%f[j]+c[j];
            }            
        }
        ans[i]=res;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}