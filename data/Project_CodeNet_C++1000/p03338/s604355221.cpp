#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    long long n,ans=0;
    string s;
    cin>>n>>s;
    for(int i=1;i<n;i++){
        map<char,int> a;
        long long c=0;
        for(int j=0;j<i;j++){
            a[s[j]]=1;
        }
        for(int j=i;j<n;j++){
            if(a[s[j]]==1){
                c++;
                a[s[j]]=0;
            }
        }
        if(c>ans){
            ans=c;
        }
    }
    cout<<ans<<endl;
    return(0);
}