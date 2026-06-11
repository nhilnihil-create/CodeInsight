#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    int k;cin>>k;
    set<string> sub; 
    for(char c='a';c<='z';c++){
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                string cc;
                cc=s[i];
                sub.insert(cc);
                for(int j=i+1;j<s.size();j++){
                    if(j-i>=5) break;
                    cc+=s[j];
                    sub.insert(cc);
                }
            }
        }
        if(sub.size()>=k) break;
    }
    vector<string> v(sub.begin(),sub.end());
    cout<<v[k-1]<<endl;
}
