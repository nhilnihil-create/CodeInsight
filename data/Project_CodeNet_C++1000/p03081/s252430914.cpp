#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,q;
    char s[200010],t[200010],d[200010];
    cin>>n>>q;
    s[0]='_';
    for(int i=1;i<=n;i++) cin>>s[i];
    s[n+1]='_';
    for(int i=0;i<q;i++) cin>>t[i]>>d[i];
    
    int l=0,r=n+1;
    for(int i=q-1;i>=0;i--){
        if(t[i]==s[l]&&d[i]=='R') l--;
        else if(t[i]==s[l+1]&&d[i]=='L') l++;
        if(t[i]==s[r]&&d[i]=='L') r++;
        else if(t[i]==s[r-1]&&d[i]=='R') r--;
    }
    
    cout<<r-l-1<<endl;
}