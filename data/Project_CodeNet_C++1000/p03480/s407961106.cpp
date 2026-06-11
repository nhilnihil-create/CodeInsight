#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    bool ok = true;
    int ans = 1e9;
    
  
    for(int i=1;i<(int)s.length();i++){
        if(s[i]!=s[i-1]){
            ans = min(ans,max(i,(int)s.length()-i));
        }
    }
    if(ans == 1e9){
        cout<<s.length()<<endl;
        return 0;
    }
    cout<<ans<<endl;
}