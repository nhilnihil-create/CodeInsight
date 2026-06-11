#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int n;cin>>n;

    queue<string> q;
    q.push("");
    int ans=0;
    while(q.size()){
        string tmp=q.front();q.pop();
        int a,b,c;a=b=c=0;
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]=='3') a++;
            if(tmp[i]=='5') b++;
            if(tmp[i]=='7') c++;
        }
        if(a>0&&b>0&&c>0&&stoll(tmp)<=n){
            ans++;
        }
        if(tmp.size()>9){
            continue;
        }
        tmp+='3';
        q.push(tmp);
        tmp.pop_back();
        tmp+='5';
        q.push(tmp);
        tmp.pop_back();
        tmp+='7';
        q.push(tmp);
        tmp.pop_back();
    }

    cout<<ans<<endl;

    return 0;
}