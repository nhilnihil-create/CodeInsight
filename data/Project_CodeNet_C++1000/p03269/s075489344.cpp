#include <bits/stdc++.h>
#define ll long long

using namespace std;

typedef struct{
    int x,y,w;
}Grana;

int l;
int n,m;
vector<int> bin;
vector<Grana> graf;

void plus1()
{
    m++;
    graf.push_back({1,n,l});
    l++;
}

void dupliraj()
{
    n++;
    m+=2;
    graf.push_back({n-1,n,0});
    graf.push_back({n-1,n,l});
    l*=2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>l;

	while(l!=0)
        bin.push_back(l%2), l/=2;

    n=2;
    m=1;
    l=1;
    int cnt=0;
    graf.push_back({1,2,0});
    for(int i=bin.size()-2;i>=0;i--)
    {
        cnt++;
        if(l==1)plus1();
        else dupliraj();
        if(bin[i]==1)
            plus1();
    }
    //cout<<"*"<<cnt<<endl;
    cout<<n<<" "<<m<<endl;
    for(int i=0;i<m;i++)
        cout<<graf[i].x<<" "<<graf[i].y<<" "<<graf[i].w<<endl;
	return 0;
}
