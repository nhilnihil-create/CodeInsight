#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans=10000;
    for(int i=0;i<s.size()-2;i++){
        int x=0;
        for(int j=0;j<3;j++){
            char t=s[i+j];
            x+=(t-'0')*pow(10,2-j);
        }
        ans=min(ans,abs(x-753));
    }
    cout<<ans<<endl;

    return 0;
}