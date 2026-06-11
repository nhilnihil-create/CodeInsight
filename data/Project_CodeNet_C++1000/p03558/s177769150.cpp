#include <bits/stdc++.h>

using namespace std;




deque<int> q;
int v[100001];

int main()
{
    int k;
    v[1]=1;
    cin>>k;
    q.push_back(1);

    while(!q.empty()){
        int d=q.front();
        q.pop_front();


        if(d==0) {
            cout<<v[d];
            return 0;
        }

        int i=(d*10)%k;

        if(v[i]==0||v[i]>v[d]){
           v[i]=v[d];
            q.push_front(i);

        }
        i++;
        i=i%k;

        if(v[i]==0||v[i]>v[d]+1){
           v[i]=v[d]+1;
            q.push_back(i);

        }
    }
    return 0;
}
