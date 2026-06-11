#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<long long> s(n);
    for(int i=0;i<n;i++){
        if(i==0)s[i]=a[i];
        else s[i]=s[i-1]+a[i];
    }
    map<long long,int> m;
    long long ret=0;
    for(int i=n-1;i>0;i--){
        m[s[i]]++;
        ret+=m[s[i-1]];
    }
    m[s[0]]++;
    ret+=m[0];
    cout<<ret<<endl;
}