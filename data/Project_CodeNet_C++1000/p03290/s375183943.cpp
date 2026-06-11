#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    int d,g;
    cin>>d>>g;
    g/=100;
    vector<int> p(d),c(d);
    
    for(int i=0;i<d;i++){
        cin>>p[i]>>c[i];
        c[i]/=100;
    }
    int ans=1000000000;
    for(int bit=0;bit<(1<<d);bit++){
        vector<int> allsolve(d);
        int points=0;
        int solvednum=0;
        for(int i=0;i<d;i++){
            if(bit&(1<<i)){
                points+=c[i]+(i+1)*p[i];
                allsolve[i]++;
                solvednum+=p[i];
            }
        }
        if(points>=g){
            ans=min(ans,solvednum);
            continue;
        }
        for(int i=d-1;i>=0;i--){
            if(allsolve[i]>0){
                continue;
            }
            for(int j=0;j<p[i];j++){
                points+=i+1;
                solvednum++;
                if(points>=g){
                    ans=min(ans,solvednum); 
                }
            }            
        }
    }
    cout<<ans<<endl;
    return 0;
}