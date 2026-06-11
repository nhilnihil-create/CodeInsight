#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;cin>>N>>M;
    vector<vector<int>> s(M,vector<int>(0)); 
    for (int i = 0; i < M; i++)
    {
        int k;cin>>k;
        for (int j = 0; j < k; j++)
        {
            int a;cin>>a;
            a--;
            s[i].push_back(a);
        }
    }
    vector<int> p(M);
    for (int i = 0; i < M; i++)cin>>p[i];
    
    long long cnt=0;
    for (int i = 0; i < (1<<N); i++)
    {
         bool ok=true;
        for (int j = 0; j < M; j++)
        {
            int on=0;
            for (int v:s[j])
            {
                if(i&(1<<v))on++;
            }
            if(on%2!=p[j])ok=false;
        }
        if(ok)cnt++;
    }
    cout<<cnt<<endl;
}