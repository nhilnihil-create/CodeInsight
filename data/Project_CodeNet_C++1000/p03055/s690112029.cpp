#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second
#define pb push_back

vector<vector<int>> E;
//Eは頂点数＋１をとっておく

int diameter(int x){//頂点数を入れる
    int ans=0,en=x;
    queue<int> q;
    vector<int> dis(x+1,0);//何マスで訪れたか
    dis.at(x)=-1;
    q.push(x);
    
    while(q.size()!=0){
        int s=q.front();
        q.pop();
        for(int i=0;i < E.at(s).size();i++)
        {
            if(dis.at(E.at(s).at(i))==0){
                dis.at(E.at(s).at(i))+=max(dis.at(s)+1,1);
                q.push(E.at(s).at(i));
                if(ans<dis.at(E.at(s).at(i))){
                    en = E.at(s).at(i);
                }
                ans=max(ans,dis.at(E.at(s).at(i)));
            }
        }
    }

    dis.assign(x+1,0);
    dis.at(en)=-1;
    q.push(en);
    while(q.size()!=0){
        int s=q.front();
        q.pop();
        for(int i=0;i < E.at(s).size();i++)
        {
            if(dis.at(E.at(s).at(i))==0){
                dis.at(E.at(s).at(i))+=max(dis.at(s)+1,1);
                q.push(E.at(s).at(i));
                ans=max(ans,dis.at(E.at(s).at(i)));
                
            }
        }
    }
    return ans;
}



int main(){
    int n,d;
    cin >> n;
    E.assign(n+1,vector<int>());
    for(int i=0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        E.at(a).pb(b);
        E.at(b).pb(a);//Edge
    }
    d=diameter(n);
    d++;
    if(d%3==2){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }
}
