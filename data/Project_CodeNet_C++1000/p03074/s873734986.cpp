#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    string s;
    int n,k,c=0;
    vector<int> a;
    cin >> n >> k >> s;
    rep(i,n){
        int j = i;
        while(s[j+1]==s[j]&&j+1<n) j++;
        a.push_back(j-i+1);
        i = j;
    }
    reverse(a.begin(),a.end());
    if(s[0]=='0') a.push_back(0);
    reverse(a.begin(),a.end());
    if(s[n-1]=='0') a.push_back(0);
    vector<int> b(a.size()+1);
    rep(i,a.size()) b[i+1] = b[i] + a[i];
    for(int i=0;i<a.size();i+=2){
        int left = i;
        int right = min(i+2*k+1,(int)a.size());//累積和としての左右
        c = max(c,b[right]-b[left]);
    }
    cout << c << endl;
}