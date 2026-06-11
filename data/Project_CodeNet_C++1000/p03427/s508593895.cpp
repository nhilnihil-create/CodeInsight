#include <bits/stdc++.h>
using namespace std;
int main(void){
    string n;
    cin>>n;
    int sum=0,flag=0,tmp=0;
    for (int j=0;j<n.size();j++) {
        tmp+=n[j]-48;
    }
    for (int i=0;i<n.size();i++) {
        if (i==0) {
            if (n[i]-48!=9) {
                sum+=n[i]-48-1;
                flag=1;
            } else {
                sum+=9;
            }
        } else if (i==n.size()-1) {
            if (flag==0&&n[i]-48!=9) {
                sum--;
                sum+=9;
            } else {
                sum+=9;
            }
        } else {
            if (n[i]!=9) {
                sum+=9;
            }
        }
    }
    cout<<max(tmp,sum)<<endl;
}