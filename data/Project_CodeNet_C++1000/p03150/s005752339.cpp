#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    if (s!="keyence") {
        for (int i=0;i+1<s.size();i++) {
            for (int j=i+1;j<s.size();j++) {
                string tmp=s;
                tmp.erase(i,j-i);
                if (tmp=="keyence") {
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
    }
}