#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <string>
#include <math.h>
using namespace std;

int main(){
    long long int n,b=10000000000,ans=0;
    cin>>n;
    vector<long long int>a(1000000);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    cout<<a[0]<<' '<<flush;
    for(int i=1;i<n;i++){
        if(a[0]%2==0){
            if(abs(a[0]/2-a[i])<b){
                b=abs(a[0]/2-a[i]);
                ans=a[i];
            }

        }
        else{
            if(abs(a[0]/2-a[i])<b||abs((a[0]+1)/2-a[i])<b){
                b=min(abs(a[0]/2-a[i]),abs((a[0]+1)/2-a[i]));
                ans=a[i];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
