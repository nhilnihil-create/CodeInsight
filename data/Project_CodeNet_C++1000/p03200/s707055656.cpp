#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    long long int sum=0;
    int countB=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='B') {
            countB++;
        } else {
            sum+=countB;
        }
    }
    cout<<sum<<endl;
}