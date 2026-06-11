#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> v[200000];
string s;
bool b[200000];
void f(int x){
    bool p=false, q=false;
    for(int i=0;i<v[x].size();i++){
        int t=v[x][i];
        if(b[t]){
            if(s[t]=='A')p=true;
            if(s[t]=='B')q=true;
        }
        if(p&&q)return;
    }
    b[x]=false;
    for(int i=0;i<v[x].size();i++){
        if(i>0){
            if(v[x][i]==v[x][i-1])continue;
        }
        int t=v[x][i];
        if(b[t]){
            f(t);
        }
    }
}
int main(void){
    int m;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    fill(b, b+n, true);
    for(int i=0;i<n;i++){
        sort(v[i].begin(), v[i].end());
    }
    for(int i=0;i<n;i++){
        f(i);
    }
    for(int i=0;i<n;i++){
        if(b[i]){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}
