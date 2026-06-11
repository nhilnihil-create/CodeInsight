#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >ans;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            if((n&1)&&i+j==n)continue;
            if(((n&1)^1)&&i+j==n+1)continue;
            ans.push_back(make_pair(i,j));
        }
    printf("%d\n",(int)ans.size());
    for(pair<int,int > p:ans)printf("%d %d\n",p.first,p.second);
    return 0;
}