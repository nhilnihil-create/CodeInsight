#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    int n,ans=0;cin>>n;
    vector<int> vec(3);
    string x;
    for(int i=0;i<n;i++){
        cin>>x;
        for(int j=0;j<x.size()-1;j++){
            if(x[j]=='A'&&x[j+1]=='B')ans++;
        }
        if(x[0]=='B'&&x[x.size()-1]=='A')vec[1]++;
        else if(x[0]=='B')vec[2]++;
        else if(x[x.size()-1]=='A')vec[0]++;
    }
    if(vec[0]==0&&vec[1]>0&&vec[2]==0){
        ans+=vec[1]-1;
    }
    else if(vec[0]==0&&vec[1]>0&&vec[2]>0){
        ans+=vec[1];
    }
    else if(vec[0]>0&&vec[1]==0&&vec[2]>0){
        ans+=min(vec[0],vec[2]);
    }
    else if(vec[0]>0&&vec[1]>0&&vec[2]==0){
        ans+=vec[1];
    }
    else if(vec[0]>0&&vec[1]>0&&vec[2]>0){
        ans+=vec[1]+1;
        ans+=min(vec[0]-1,vec[2]-1);
    }
    cout<<ans<<endl;
}
