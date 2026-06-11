#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    vector<long long int>a(200000);
    long long int n,c=-1,ans=0;
    cin>>n;
    for(long long int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    for(long long int i=0;i<n;i++){
        if(a[i]!=a[i+1]){
            if(a[i]>i-c){
                ans+=(i-c);
            }
            else{
                ans+=(i-c-a[i]);
            }
            c=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
