#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
    double n,ans=0;
    cin>>n;
    vector<double>a(1000000);
    vector<string>s(1000000);

    for(int i=0;i<n;i++){
       cin>>a[i]>>s[i];
       if(s[i]=="JPY"){
           ans+=a[i];
       }
       else{
           ans+=a[i]*380000;
       }
    }

    cout<<fixed << setprecision(16)<<ans<<endl;
    return 0;
}