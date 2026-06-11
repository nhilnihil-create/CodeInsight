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

//(*'ω'*)ACcept me...
int main(){
    int n;cin>>n;
    vector<pair<int,int>> vec(n,pair<int,int>(0,0));
    for(int i=0;i<n;i++){
        cin>>vec[i].first;
        vec[i].second=i+1;
    }
    vector<int> ans(n);
    for(int rep=0;rep<n;rep++){
        bool found=false;
        for(int i=n-1;i>=0;i--){
            if(vec[i].first!=vec[i].second)continue;
            found=true;
            ans[rep]=vec[i].first;
            vec[i].second=-1;
            for(int j=i+1;j<n;j++)vec[j].second--;
            break;
        }
        if(!found){
            cout<<-1<<endl;return 0;
        }
    }
    for(int i=n-1;i>=0;i--){
        cout<<ans[i]<<endl;
    }
}
