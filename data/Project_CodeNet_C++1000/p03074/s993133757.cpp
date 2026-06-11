#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(s[0]=='0')k--;
    int m=0,p=0;
    vector<int>x(1,-1);
    for(int i=0;i<n;i++){
        if(k<0){
            k++;
            p++;
        }
        if(s[i]=='1' && s[i+1]=='0')k--;
        if(s[i]=='0' && s[i+1]=='1')x.push_back(i);
        m=max(m,i-x[p]);
    }
    cout<<m<<endl;
    return 0;
}