#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,k;string s;
    cin>>n>>k>>s;
    vector<int> a;
    a.push_back(0);
    int c=1;
    for (int i=0;i<n;i++) {
        if (i==n-1)
            a.push_back(a.back()+c);
        else if (s[i]==s[i+1])
            c++;
        else {
            a.push_back(a.back()+c);
            c=1;
        }
    }
    int mx=0;
    if (s[0]=='0')
        mx=max(mx,a[min(2*k,(int)a.size()-1)]-a[0]);
    for (int i=s[0]=='0';i<a.size();i+=2)
        mx=max(mx,a[min(i+2*k+1,(int)a.size()-1)]-a[i]);
    cout<<mx<<endl;
    return 0;
}