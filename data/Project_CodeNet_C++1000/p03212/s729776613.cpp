#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    string n;
    cin>>n;
    ll nLL=stoll(n);
    queue<string> strq;
    strq.push("7");
    strq.push("5");
    strq.push("3");
    vector<string> pre;
    while(!strq.empty()){
        string tempstr=strq.front();strq.pop();
        ll tempLL=stoll(tempstr);
        if(tempLL<=nLL){
            pre.push_back(tempstr);
            strq.push(tempstr+'7');
            strq.push(tempstr+'5');
            strq.push(tempstr+'3');
        }        
    }
    int ans=0;
    for(int i=0;i<pre.size();i++){
        bool find3=(pre[i].end()!=find(pre[i].begin(),pre[i].end(),'3'));
        bool find5=(pre[i].end()!=find(pre[i].begin(),pre[i].end(),'5'));
        bool find7=(pre[i].end()!=find(pre[i].begin(),pre[i].end(),'7'));
        if(find3&find5&find7){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}