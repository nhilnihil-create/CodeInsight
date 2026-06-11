#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> s(m,vector<int>());
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int a;
            cin>>a;   
            a--;
            s[i].push_back(a);
        }
    }
    vector<int> p(m);
    for(int i=0;i<m;i++) cin>>p[i];

    int ans=0;
    for(int i=0;i<(1<<n);i++){
        bool flag=true;
        for(int j=0;j<m;j++){
            int cnt=0;
            for(int k : s[j]){
                if(i&(1<<k)) cnt++;
            }
            if(cnt%2!=p[j]) flag=false;
        }
        if(flag) ans++;
    }
    cout<<ans<<endl;
}