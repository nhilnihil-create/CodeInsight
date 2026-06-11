#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int ans=100000;
    for (int i=1;n-i>0;i++) {
        int sum=0;
        string tmp1=to_string(i);
        string tmp2=to_string(n-i);
        for (int j=0;j<tmp1.size();j++) {
            sum+=tmp1[j]-48;
        }
        for (int k=0;k<tmp2.size();k++) {
            sum+=tmp2[k]-48;
        }
        if (sum<ans) {
            ans=sum;
        }
    }
    cout<<ans<<endl;
}