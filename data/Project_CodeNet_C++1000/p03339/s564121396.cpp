#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N;
    string s;
    cin >> N >> s;
    vector<int> et(N, 0);
    vector<int> wt(N, 0);
    for (int i = 0; i < N; i++)
    {
        wt[i] += (s[i]=='W');
        if(i+1<N)wt[i+1]=wt[i];
    }
    for (int i = N-1; i >= 0; i--)
    {
        et[i] += (s[i]=='E');
        if(i-1>=0)et[i-1]=et[i];
    }
    int ans=N;
    for (int i = 0; i < N; i++)
    {
        int t;
        if(i==0)t=et[1];
        else if(i==N-1)t=wt[N-2];
        else t = wt[i-1]+et[i+1];
        ans = min(ans, t);
    }
    
    cout << ans << endl;
}