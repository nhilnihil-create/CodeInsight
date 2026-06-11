#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,m,c;
    cin>>n>>m>>c;
    int a[m],b[m];
    for(int i=0;i<m;i++)cin>>b[i];
    int ans=0;
    for(int i=0;i<n;i++){
        int tmp=0;
        for(int j=0;j<m;j++){
            cin>>a[j];
            tmp+=a[j]*b[j];
        }
        if(tmp+c>0)ans++;
    }
    cout<<ans<<endl;
    return 0;
}