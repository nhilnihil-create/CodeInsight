#include <bits/stdc++.h>

#define pan(i,n) for(int i=0;i<n;i++)
#define pans(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define INF 1e9+7
#define PI 3.141592653
#define inf 100007

using namespace std;

int main(){
    int n,a=0,b=0,ba=0,ans=0;
    cin>>n;
    string s; 
    pan(i,n){
        cin>>s;
        pan(i,(int)s.size()-1){
            if(s[i]=='A'&& s[i+1]=='B') ans++;
        }
        if(s[0]=='B' && s[(int)s.size()-1]=='A') ba++;
        else{
            if(s[0]=='B' ) b++;
            if(s[(int)s.size()-1]=='A') a++;
        }
    }
    if(ba==0) ans+=min(a,b);
    else{
        if(a+b>0) ans=ans+ba+min(a,b);
        else if(a+b==0) ans=ans+ba-1;
    }
    cout<<ans;
}