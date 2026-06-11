#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> topological(vector<vector<int>> E)
{
    int n = (int)E.size();
    
    vector<int> C(n);
    for (int i=0; i<n; i++)
        for (int e: E[i])
            C[e]++;

    vector<int> V;
    vector<int> S;
    for (int i=0; i<n; i++)
        if (C[i]==0)
            S.push_back(i);

    while (!S.empty())
    {
        int v = S.back();
        S.pop_back();
        V.push_back(v);
        for (int e: E[v])
            if (--C[e]==0)
                S.push_back(e);
    }

    return (int)V.size()==n ? V : vector<int>();
}

int main()
{
    int N, M;
    cin>>N>>M;
    string s;
    cin>>s;
    vector<vector<int>> E(N);
    for (int i=0; i<M; i++)
    {
        int a, b;
        cin>>a>>b;
        E[a-1].push_back(b-1);
        E[b-1].push_back(a-1);
    }

    vector<vector<int>> E2(2*N);
    for (int i=0; i<N; i++)
    for (int e: E[i])
    {
        if (s[i]==s[e])
            E2[2*i].push_back(2*e+1);
        else
            E2[2*i+1].push_back(2*e);
    }

    cout<<(topological(E2).empty() ? "Yes" : "No")<<endl;
}
