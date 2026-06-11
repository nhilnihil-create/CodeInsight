#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int ans=0;
    for(int i=1;i<n;i++){
        int sum=0;
        string s1,s2;
        s1=s.substr(0,i);
        s2=s.substr(i,n-i);
        vector<int>a1(26);
        vector<int>a2(26);
        for(int j=0;j<s1.length();j++){
            a1[s1[j]-'a']++;
        }
        for(int j=0;j<s2.length();j++){
            a2[s2[j]-'a']++;
        }
        for(int j=0;j<26;j++){
            if(a1[j]>0&&a2[j]>0)sum++;
        }
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}