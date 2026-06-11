#include <bits/stdc++.h>

#define pan(i,n) for(int i=0;i<n;i++)
#define pans(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define INF 1000000007
#define PI 3.141592653
#define inf 100007
#define P pair<ll,ll>

using namespace std; 

int main(){
    string s,d="";
    cin>>s;
    int n=s.size(),ans=0,i=0;
    while(i<n){
        if(s[i]==s[n-1]){
            i++,n--;
        }
        else{
            if(s[i]=='x') ans++,i++;
            else if(s[n-1]=='x') ans++,n--;
            else{
                ans=-1;
                break;
            }
        }
    }
    cout<<ans;
}