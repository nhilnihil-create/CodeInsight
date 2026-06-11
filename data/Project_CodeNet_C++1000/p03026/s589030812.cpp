#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
int main() {
    int N;
    cin>>N;
    vector<vector<int> >a(N);
    for(int i=0;i<N-1;i++){
        int l,m;
        cin>>l>>m;
        l--;
        m--;
        a[l].push_back(m);
        a[m].push_back(l);

    }
    int c[N];
    for(int i=0;i<N;i++){
        cin>>c[i];
    }
    sort(c,c+N);
    reverse(c,c+N);
    int ne=-1;
    int kazu=-1;
    for(int i=0;i<N;i++){
        if((int)a[i].size()>kazu){
            kazu=a[i].size();
            ne=i;
        }

    }
    queue<int>bfs;
    int used[N];
    for(int i=0;i<N;i++){
        used[i]=-1;

    }
    int ans[N];
    int now=0;
    bfs.push(ne);
    used[ne]=1;
    while(!bfs.empty()){
        int m=bfs.front();
        bfs.pop();
        used[m]=1;
        ans[m]=c[now];
        now++;
        for(int i=0;i<a[m].size();i++){
            if(used[a[m][i]]!=1){
                bfs.push(a[m][i]);
            }
        }
    }
    int sum=0;
    for(int i=1;i<N;i++){
        sum+=c[i];
    }
    cout<<sum<<endl;
    for(int i=0;i<N;i++){
        cout<<ans[i];
        if(i==N-1){
            cout<<""<<endl;
        }else{
            cout<<" ";
        }
    }



}











