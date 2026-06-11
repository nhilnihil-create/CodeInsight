#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,ans=0;
    cin>>n;
    string s;
    cin>>s;
    f(i,0,n){
        long long d=0;
        vector<long long> a(26),b(26);
        f(j,0,i){
            a[s[j]-'a']++;
        }
        f(j,i,n){
            b[s[j]-'a']++;
        }
        f(j,0,26){
            if(a[j]>0&&b[j]>0){
                d++;
            }
        }
        ans=max(ans,d);
    }
    cout<<ans<<endl;
    return 0;
}
