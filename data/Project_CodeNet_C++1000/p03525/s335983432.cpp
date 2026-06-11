#include<bits/stdc++.h>
using namespace std;
int num[30];
vector<int> ve;
vector<int> vi;
vector<int> tmp;
int main(){
    int n;
    cin>>n;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        num[x]++;
    }
    if(num[0]>0){
        puts("0");
        return 0;
    }
    for(int i=0;i<=12;i++){
        if(num[i]==0) continue;
        if(num[i]>2){
            puts("0");
            return 0;
        }
        if(num[i]==2){
            //cout<<i<<" "<<24-i<<endl;
            ve.push_back(i);
            ve.push_back(24-i);
        }
        if(num[i]==1){
            vi.push_back(i);
        }
    }
    int len=vi.size();
    int ans=0;
    if(len==0){
        ve.push_back(0);
        ve.push_back(24);
        sort(ve.begin(),ve.end());
        ans=100;
        for(int i=1;i<ve.size();i++){
            ans=min(ans,ve[i]-ve[i-1]);
        }
        cout<<ans<<endl;
        return 0;
    }
    for(int i=0;i<(1<<len);i++){
        tmp.clear();
        for(int j=0;j<len;j++){
            if((i>>j)&1) tmp.push_back(vi[j]);
            else tmp.push_back(24-vi[j]);
        }
        for(int j=0;j<ve.size();j++){
            tmp.push_back(ve[j]);
        }
        tmp.push_back(0);
        tmp.push_back(24);
        int ff=100;
        sort(tmp.begin(),tmp.end());
        //for(int j=0;j<tmp.size();j++) cout<<tmp[j]<<endl;
        for(int j=1;j<tmp.size();j++){
            ff=min(ff,tmp[j]-tmp[j-1]);
        }
        ans=max(ans,ff);
    }
    cout<<ans<<endl;
}
