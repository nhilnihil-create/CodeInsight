#include <bits/stdc++.h>

using namespace std;


bool comp(pair<int,int> a, pair<int,int> b)
{
    if (a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}

int main()
{
    int ans = 0, n, m;
    cin>>n>>m;
    vector<pair<int,int>> V(m);
    for (int i=0; i< m; i++)
        cin>>V[i].first>>V[i].second;
    
    sort(V.begin(), V.end(), comp);
    int fin = 0;
    for (int i=0; i<m; i++)
    {
    	if(fin <= V[i].first){
    		ans++;
    		fin = V[i].second;
    	}
    }
    cout<< ans;
    return 0;
}