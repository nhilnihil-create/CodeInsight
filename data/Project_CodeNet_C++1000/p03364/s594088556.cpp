#include <iostream>
using namespace std;
int n,ans;
string s[300],t[300];
bool solve(void){
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(t[i][j]!=t[j][i])return false;
        }
    }
    return true;
}
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        t[i]=s[i];
    }
    ans+=solve();
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                t[(j+i)%n][k]=s[j][k];
            }
        }
        ans+=solve();
    }
    cout<<ans*n<<endl;
}
