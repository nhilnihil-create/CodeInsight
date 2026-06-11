#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
using namespace std;
 
 
int main() {
    int n;
    string s;
    cin>>n>>s;
    
    int count=0, ans=-1;
    for(int i=1; i<n; ++i) {
        if(s[i]=='E') ++count;
    }

    ans=count;
    for(int i=1; i<n; i++) {
        if(s[i-1]=='W') ++count;
        if(s[i]=='E') --count;
        ans=min(ans,count);
    }
    cout<<ans<<endl;

    return 0;
}