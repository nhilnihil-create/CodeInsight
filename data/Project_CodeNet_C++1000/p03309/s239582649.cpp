#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n),ar(n);
    for(int i=0;i<n;i++){
        cin>>a.at(i);
        ar.at(i)=a.at(i)-i-1;
    }
    sort(ar.begin(),ar.end());

    int mid = ar.at(n/2);

    long long ans = 0;

    for(int i=0;i<n;i++)
        ans+=abs(mid-ar.at(i));
    
    cout<<ans<<endl;

    return 0;
}