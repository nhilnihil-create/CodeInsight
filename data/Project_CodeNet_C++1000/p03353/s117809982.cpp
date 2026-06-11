#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int k;
    cin>>k;
    set<string>x;
    for(int i=0;i<k;i++){
        for(int j=0;j+i<n;j++){
            string subs;
            for(int l=j;l<=j+i;l++)subs.push_back(s[l]);
            x.insert(subs);
        }
    }
    auto itr=x.begin();
    for(int i=0;i<k-1;i++)++itr;
    cout<<*itr<<endl;
    return 0;
}