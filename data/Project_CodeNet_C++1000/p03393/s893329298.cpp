#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

int main(){
    string s;cin>>s;
    vector<bool> used(26,false);
    for(int i=0;i<(int)s.size();i++){
        used[(int)(s[i]-'a')]=true;
    }
    for(int i=0;i<26;i++)if(!used[i]){
        cout<<s+(char)(i+'a')<<endl;
        return 0;
    }
    fill(used.begin(),used.end(),false);
    for(int i=(int)s.size()-1;i>=0;i--){
        for(int j=(int)(s[i]-'a');j<26;j++){
            if(used[j]){
            cout<<s.substr(0,i)+(char)(j+'a')<<endl;
            return 0;
            }
        }
        used[(int)(s[i]-'a')]=true;
    }
    cout<<-1<<endl;
    return 0;
}