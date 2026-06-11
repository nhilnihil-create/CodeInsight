#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    long long m;
    cin>>n>>m;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    long long ans=0;
    map<long long,int> mp;
    mp[0]=1;
    long long tmp=0;
    for(int i=0;i<n;i++){
        tmp+=a[i];
        tmp%=m;
        ans+=mp[tmp];
        mp[tmp]+=1;
    }

    cout<<ans<<endl;

    return 0;
}