#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,m;
    cin>>n>>m;
    long long int a=n,b=m;
    while (a%b!=0) {
        long long int tmp=b;
        b=a%b;
        a=tmp;
    }
    long long int l=(n*m)/b;
    string s,t;
    cin>>s>>t;
    std::map<long long int, char> W;
    for (long long int i=0;i<n;i++) {
        W[i*(l/n)]=s[i];
    }
    for (long long int i=0;i<m;i++) {
        if (W[i*(l/m)]=='\0') {
            W[i*(l/m)]=t[i];
        } else if (W[i*(l/m)]!=t[i]) {
            cout<<-1<<endl;
            return 0;
        } else {
            W[i*(l/m)]=t[i];
        }
    }
    cout<<l<<endl;
}
