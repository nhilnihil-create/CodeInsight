#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mx=0;
    int arr1[26],arr2[26];
    string s;
    cin>>n>>s;
    for(int i=1;i<n;i++) {
        memset(arr1,0,sizeof arr1);
        memset(arr2,0,sizeof arr2);
        int cnt = 0;
        for(int j=i-1;j>=0;j--) {
            arr1[s[j]-'a']++;
        }
        for(int j=i;j<n;j++){
            arr2[s[j]-'a']++;
        }
        for(int i=0;i<26;i++) {
            if(arr1[i] && arr2[i]) cnt++;
        }
        mx = max(mx,cnt);
    }
    cout<<mx<<endl;
}
